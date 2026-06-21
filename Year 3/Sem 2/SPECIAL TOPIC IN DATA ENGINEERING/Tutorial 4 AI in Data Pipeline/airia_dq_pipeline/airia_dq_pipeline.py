"""
Demo Apache Airflow DAG:
AI-assisted data quality pipeline using the Airia AI Agent API.

Task flow:
extract_data >> load_data >> airia_data_quality_check >> transform_data

This code is intentionally beginner-friendly for a university tutorial.
It is not production-level code.
"""

from __future__ import annotations

import json
import os
import shutil
from datetime import datetime
from pathlib import Path

import pandas as pd
import requests
from airflow import DAG
from airflow.providers.standard.operators.python import PythonOperator


AIRIA_ENDPOINT = (
    "https://api.airia.ai/v2/PipelineExecution/"
    "a5323a4c-f6cd-4082-ac07-b52c1f7bc4c5"
)

# Keep demo files next to this DAG file.
PROJECT_DIR = Path(__file__).resolve().parent
SOURCE_CSV = PROJECT_DIR / "customer_data.csv"
STAGING_DIR = PROJECT_DIR / "staging"
STAGED_CSV = STAGING_DIR / "customer_data_staged.csv"
OUTPUT_DIR = PROJECT_DIR / "output"
TRANSFORMED_CSV = OUTPUT_DIR / "customer_data_clean.csv"
AIRIA_REPORT_FILE = OUTPUT_DIR / "airia_data_quality_report.md"


def extract_data() -> str:
    """
    Read the dummy customer CSV file.

    In this demo, the CSV is already included in the project. If the file is
    missing, the task fails so we know the input dataset was not copied into
    the Airflow DAG folder.
    """
    if not SOURCE_CSV.exists():
        raise FileNotFoundError(f"Input CSV file not found: {SOURCE_CSV}")

    print(f"Extracted CSV file: {SOURCE_CSV}")
    return str(SOURCE_CSV)


def load_data() -> str:
    """
    Simulate loading the extracted CSV file into a staging area.

    A real pipeline might load data into a database or cloud storage.
    For this demo, we copy the file into a local staging folder.
    """
    STAGING_DIR.mkdir(exist_ok=True)
    shutil.copyfile(SOURCE_CSV, STAGED_CSV)

    print(f"Loaded CSV into staging: {STAGED_CSV}")
    return str(STAGED_CSV)


def _response_contains_critical_issues(response_data: object) -> bool:
    """
    Simple helper for demo purposes.

    The exact Airia response structure can vary depending on the agent design,
    so this function checks the response text for the word "critical". It avoids
    treating phrases like "no critical issues" as a failure.
    """
    response_text = json.dumps(response_data, indent=2).lower()

    safe_phrases = [
        "no critical issue",
        "no critical issues",
        '"critical_issues": []',
        '"criticalIssues": []'.lower(),
    ]
    if any(phrase in response_text for phrase in safe_phrases):
        return False

    return "critical" in response_text


def _extract_airia_report(response_data: object) -> str:
    """
    Get the readable report text from the Airia response.

    Airia returns the main answer in the "result" field for this demo. If the
    response shape changes, we fall back to a formatted JSON string.
    """
    if isinstance(response_data, dict):
        result = response_data.get("result")
        if isinstance(result, str) and result.strip():
            return result

        raw_response = response_data.get("raw_response")
        if isinstance(raw_response, str) and raw_response.strip():
            return raw_response

    return json.dumps(response_data, indent=2)


def airia_data_quality_check() -> None:
    """
    Send the CSV content to Airia for an AI-assisted data quality check.

    Important: the CSV content is sent directly in userInput because the Airia
    API cannot read a local file path from your computer.
    """
    api_key = os.getenv("AIRIA_API_KEY")
    if not api_key:
        raise Exception("AIRIA_API_KEY environment variable is not set.")

    csv_content = STAGED_CSV.read_text(encoding="utf-8")

    user_input = f"""
Please perform a data quality check on this customer CSV data.

Look for missing values, invalid emails, invalid ages, invalid dates,
duplicate records, missing countries, and negative spending amounts.

Return a short report. Clearly mention whether there are critical issues.

CSV content:
{csv_content}
"""
    payload = {
        "userInput": user_input,
        "asyncOutput": False,
    }

    headers = {
        "X-API-KEY": api_key,
        "Content-Type": "application/json",
    }

    response = requests.post(
        AIRIA_ENDPOINT,
        headers=headers,
        json=payload,
        timeout=60,
    )
    response.raise_for_status()

    try:
        response_data = response.json()
    except ValueError:
        response_data = {"raw_response": response.text}

    report_text = _extract_airia_report(response_data)

    OUTPUT_DIR.mkdir(exist_ok=True)
    AIRIA_REPORT_FILE.write_text(report_text, encoding="utf-8")

    print("Airia raw API response:")
    print(json.dumps(response_data, indent=2))

    print("\nReadable Airia data quality report:")
    print(report_text)
    print(f"\nAiria report saved to: {AIRIA_REPORT_FILE}")

    if _response_contains_critical_issues(response_data):
        print(
            "Critical data quality issues detected by Airia. "
            "Continuing to transform_data so the demo can clean the dataset."
        )
        return
    print("No critical data quality issues detected. Continuing pipeline.")


def transform_data() -> str:
    """
    Clean and transform the staged data after the AI data quality report.

    For this demo, the AI agent reports the issues and this Python task applies
    simple, explainable cleaning rules with pandas.
    """
    OUTPUT_DIR.mkdir(exist_ok=True)

    df = pd.read_csv(STAGED_CSV)
    original_count = len(df)

    # Simple example transformations for tutorial purposes.
    df["name"] = df["name"].str.strip()
    df["email"] = df["email"].str.lower().str.strip()
    df["country"] = df["country"].fillna("Unknown")
    df["age"] = pd.to_numeric(df["age"], errors="coerce")
    df["total_spend"] = pd.to_numeric(df["total_spend"], errors="coerce")
    df["signup_date"] = pd.to_datetime(df["signup_date"], errors="coerce")

    # Remove duplicate customer records.
    df = df.drop_duplicates()

    # Keep rows that pass the most important quality rules.
    valid_email = df["email"].str.contains(r"^[^@\s]+@[^@\s]+\.[^@\s]+$", na=False)
    valid_age = df["age"].between(0, 120)
    valid_date = df["signup_date"].notna()
    valid_spend = df["total_spend"].ge(0)
    df = df[valid_email & valid_age & valid_date & valid_spend].copy()

    # Fill remaining non-critical missing values.
    median_age = df["age"].median()
    if pd.notna(median_age):
        df["age"] = df["age"].fillna(median_age)
    df["country"] = df["country"].replace("", "Unknown").fillna("Unknown")

    # Save dates in a simple CSV-friendly format.
    df["signup_date"] = df["signup_date"].dt.strftime("%Y-%m-%d")

    df.to_csv(TRANSFORMED_CSV, index=False)

    print(f"Original rows: {original_count}")
    print(f"Clean rows written: {len(df)}")
    print(f"Transformed CSV written to: {TRANSFORMED_CSV}")
    return str(TRANSFORMED_CSV)


default_args = {
    "owner": "student",
    "retries": 0,
}


with DAG(
    dag_id="airia_dq_pipeline",
    description="Demo AI-assisted data quality pipeline using Airia AI Agent API",
    default_args=default_args,
    start_date=datetime(2026, 1, 1),
    schedule=None,
    catchup=False,
    tags=["demo", "airia", "data-quality"],
) as dag:
    extract_task = PythonOperator(
        task_id="extract_data",
        python_callable=extract_data,
    )

    load_task = PythonOperator(
        task_id="load_data",
        python_callable=load_data,
    )

    dq_check_task = PythonOperator(
        task_id="airia_data_quality_check",
        python_callable=airia_data_quality_check,
    )

    transform_task = PythonOperator(
        task_id="transform_data",
        python_callable=transform_data,
    )

    extract_task >> load_task >> dq_check_task >> transform_task

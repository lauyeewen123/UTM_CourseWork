# DATA QUALITY REPORT - EXECUTIVE SUMMARY

**Report Date:** June 14, 2026  
**Total Records:** 60 customers  
**Defect Rate:** 23% (14 records with issues)

---

## 📊 RECORD ISSUES BREAKDOWN

| Severity | Count | Status |
|----------|-------|--------|
| 🔴 **CRITICAL** | 6 | **Blocks Analysis** |
| 🟠 **WARNING** | 5 | Requires Review |
| 🔵 **INFO** | 3 | Low Priority |

---

## 🔴 TOP 5 CRITICAL ISSUES

| # | Issue Type | Count | Examples |
|---|-----------|-------|----------|
| 1 | **Invalid Email Format** | 2 | Row 2: `ben.tan.example.com`, Row 60: `hui.ling.example.com` (missing "@") |
| 2 | **Invalid Age Values** | 3 | Row 4: `-5` (negative), Row 8: `150`, Row 56: `122` (unrealistic) |
| 3 | **Invalid Date Format** | 2 | Row 5: `not-a-date`, Row 57: `2025-13-01` (month 13 invalid) |
| 4 | **Duplicate Records** | 2 | Rows 1 & 7: Aisha Rahman (identical), Rows 34 & 59: Grace Tan (identical) |
| 5 | **Negative Spending** | 2 | Row 8: `-$20.00`, Row 58: `-$15.00` |

---

## ⚠️ ADDITIONAL ISSUES

- **Missing Values:** Row 3 (age null), Row 6 (country null)
- **Unrealistic Age:** Row 56 (age 122 - exceeds reasonable lifespan)

---

## ✅ RECOMMENDED SOLUTION

1. **Delete/Correct Critical Records:** Remove or fix rows 2, 4, 5, 8, 57, 60 immediately
2. **Resolve Duplicates:** Keep one authoritative record for rows 1/7 and 34/59; delete duplicates
3. **Fill Missing Data:** Contact customers for rows 3 & 6 or exclude from analysis
4. **Validate Negative Spend:** Confirm if refunds (intentional) or data entry errors; correct if needed
5. **Implement Controls:** Add validation rules at data entry:
   - Email format validation (regex pattern)
   - Age range constraint (18–100 years)
   - Date format enforcement (YYYY-MM-DD)
   - Positive spending amount checks
   - Duplicate detection on customer_id

---

## 🚨 VERDICT

**❌ NOT READY FOR ANALYSIS**  
Data must be cleaned before use in reporting or modeling.
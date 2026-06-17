//LAU YEE WEN A23CS0099
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

double calculateKeywordPercentage(char[], int,char[]);

int main()
{
	ifstream inputFile;
	inputFile.open("input2.txt");
	
    ofstream outputFile; 	// Open the output file
	outputFile.open("output2.txt");
	
	if(!inputFile.is_open())
	{
		cout << "Error: Unable to open input file.\n";
		return 1;
	}
	else
		cout << "Results written to 'output2.txt'.\n";
	
	
	const int MAX_SIZE= 1000;
	char userInput[MAX_SIZE];
	char keyword[]= "data";
	
	inputFile.getline(userInput, MAX_SIZE, '\n');

    // Check if the output file is open
    if (!outputFile.is_open()) 
	{
        cout << "Error: Unable to open output file.\n";
        return 1; // Exit with an error code
    }

// Display and write the results to the output file	
	outputFile << "Input:" << endl;
    outputFile << userInput << endl;
    
	int length = strlen(userInput); //actual length
	
    double percentage= calculateKeywordPercentage(userInput, MAX_SIZE,keyword);

    outputFile << endl << "Percentage of words containing '" << keyword << "': " << fixed << setprecision(2) << percentage << "%" << endl << endl;

    // Close the output file
	outputFile.close();
	inputFile.close();
    
    return 0;

}

double calculateKeywordPercentage(char input[], int SIZE, char keyword[] )
{
	int length = 0, keywordCount = 0, wordCount = 0;
	
	length = strlen(input); //actual length
	
    // Convert the input string to lowercase
    for (int i = 0; i < length; i++) 
	{
        input[i] = tolower(input[i]);
    }

    // Convert the keyword to lowercase
    for (int i = 0; i < strlen(keyword); i++) 
	{
        keyword[i] = tolower(keyword[i]);
    }

    for (int i = 0; i < length; i++) 
	{
        if (strstr(input + i, keyword) == input + i)
            keywordCount++;

        if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n') 
		{
            // Check for the beginning of a word
            if (i == 0 || input[i - 1] == ' ' || input[i - 1] == '\t' || input[i - 1] == '\n')
                wordCount++;
        }
    }
    
    double percentage = (static_cast<double>(keywordCount) / wordCount) * 100.0;
    return percentage;
} 

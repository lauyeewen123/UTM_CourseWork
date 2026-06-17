//LAU YEE WEN A23CS0099
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
double calculateKeywordPercentage(char[], int,char[]);

int main()
{
	const int MAX_SIZE= 1000;
	char userInput[MAX_SIZE];
	char keyword[]= "data";
	
	cout << "Enter the input(up to 999 characters, end with an empty line): " <<endl;
	cin.getline(userInput, MAX_SIZE);
	
	cout << "Input:" << endl;
    cout << userInput << endl;
    
	int length = strlen(userInput); //actual length
	
    double percentage= calculateKeywordPercentage(userInput, MAX_SIZE,keyword);

    cout << endl << "Percentage of words containing '" << keyword << "': " << fixed << setprecision(2) << percentage << "%" << endl << endl;

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

        if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n') // check the current character is a word or not
		{
            // Check for the beginning of a word
            if (i == 0 || input[i - 1] == ' ' || input[i - 1] == '\t' || input[i - 1] == '\n')
                wordCount++;
        }
    }
    
    double percentage = (static_cast<double>(keywordCount) / wordCount) * 100.0;
    return percentage;
} 

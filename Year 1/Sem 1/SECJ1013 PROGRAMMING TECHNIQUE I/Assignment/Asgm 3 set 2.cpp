//LAU YEE WEN A23CS0099
//CHERYL CHEONG KAH VOON A23CS0060
#include <iostream>
using namespace std;

const int MAX_OPERATIONS = 100; //declare constant
int operands1 [MAX_OPERATIONS];
int results [MAX_OPERATIONS];

// funtion prototype
int multiplyUsingAddition (int , int);
void displayMainMenu();
void performMultiplication(int &);
void displayResults(int);

int main()
{
	int operationCount = 0,choice;
	do
	{
		displayMainMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice)
		{
		case 1: performMultiplication (operationCount); 
				break;
				
		case 2: displayResults(operationCount);
				cout <<endl;
				break;
				
		case 3: cout <<"\nGoodBye!" <<endl; break;
		
		default: cout << "\nInvalid choice. Please try again.\n\n"; 
				 break;
		}
	} while(choice !=3);

    system("paused");
	return 0;
}

int multiplyUsingAddition (int a, int b)
{
	int result = 0;
	for (int i=0; i<b ; i++)
	{
		result = result+a;
	}
	
	return result;
}

void displayMainMenu()
{
	cout << "\n<<<<<Main Menu>>>>>" <<endl;
	cout << "========================" <<endl;
	cout << "1. Perform Multiplication" <<endl;
	cout << "2. Display Results" <<endl;
	cout << "3. Quit" <<endl;
}

void performMultiplication(int &operationCount)
{
	int operand,result = 1;
	cout << "\nEnter the number of operand for multiplication: "; //number of integers
	cin >> operands1[operationCount];
	
	for(int i=0; i<operands1[operationCount]; i++)
	{
		cout << "Enter operand "<<(i+1) <<": ";
		cin >> operand;
		result = multiplyUsingAddition(operand, result);
	}
	cout << endl;
	cout << "\nMultiplication performed successfully!" <<endl; 
			
	results[operationCount] = result;
	operationCount++;
}

void displayResults(int operationCount)
{
	if(operationCount > 0)
	{
		cout << "\nResults of Mathematical Operations: " << endl;
		cout << "==========================================" << endl;
		for (int i=0; i<operationCount ; i++)
		{
			cout << "Operation " <<(i+1) << ": " <<results[i];
			cout<<" (Operands: " <<operands1[i] <<")" <<endl;
		}
	}
	else
       	cout << "\nNo Operation performed.\n";    
}



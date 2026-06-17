#include <iostream>
using namespace std;

const int NAMES = 3, SIZE = 10;
char students [NAMES][SIZE] = {"Ann", "Bill", "Cindy"};

int main()
{
	// display all elements
	for (int i=0; i < NAMES; i++)
	{
		cout << students[i] <<" ";
	}
	cout <<endl;
	
	// diff method to display all elements
	for (int i=0; i < NAMES; i++)
	{
		for (int j=0 ; j <SIZE; j++)
			cout << students[i][j];
		cout << " ";
	}
	cout << endl;
	
	for (int i=0; i < NAMES; i++)
	{
		for (int j=0 ; j <SIZE; j++)
			cout << students[i][j] << " ";
	}
	cout << endl;
	
	cout << students[0]; //char data type will display first element
	return 0;
}



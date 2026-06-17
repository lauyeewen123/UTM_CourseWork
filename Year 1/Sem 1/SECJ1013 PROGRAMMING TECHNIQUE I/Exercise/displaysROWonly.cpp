#include <iostream>
using namespace std;

const int NUM_STUDENTS = 3;
const int NUM_SCORES = 5;
double total;
double average;
double scores[NUM_STUDENTS] [NUM_SCORES]= {{88,97,79,86,94}, {86,91,78,79,84}, {82,73,77,82,89}};

int main()
{
	for (int j=0; j< NUM_SCORES; j++)
	{
		cout << scores[0][j]<<" "; //display 1st row only
	}
	
	int i=0;
	cout << scores[i]; //display address
	
	cout << endl;
	
	for (int i=0; i< NUM_STUDENTS; i++)
	{
		cout << scores[i][0] <<" ";//display 1st column only
		cout << endl;
	}
	
	int i=0;
	cout << scores[i]; //display address bcz not char data type
	
	return 0;
}


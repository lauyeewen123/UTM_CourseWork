#include<iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
	char input1[3];
	char input2[6];
	
	cout << "Enter your first name: " ;
	cin>> input1;
	
	cout << "Enter your last name: ";
	cin>> input2;
	
	cout<< "The name is : " << strcat(input1,input2);
	return 0;
}

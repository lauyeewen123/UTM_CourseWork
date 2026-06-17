#include<iostream>
#include <cctype>
using namespace std;

int main()
{
	char input[7];
	cout << "Enter a name: " ;
	cin>> input;
	for( int i= 0; input[i] != '\0'; i=i++)
		input[i] = toupper(input[i]);
	cout<< "The name is : " << input;
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int num, factorial=1;
	cout<< "Enter Number to find its factorial : ";
	cin >>num;
	
	for(int i =num; i>=1; i--)
	{
		if(i ==1)
			cout << i << " = ";
		else
			cout << i << " * ";
			
		factorial = factorial*i;       
	}
	cout <<factorial;
	cout << "\nThis is factorial for "<< num;
	return 0;
}

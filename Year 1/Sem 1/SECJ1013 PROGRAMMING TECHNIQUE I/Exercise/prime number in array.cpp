#include <iostream>
using namespace std;

int main()
{
	int size;
	cout<<"Enter the size of array: ";
	cin>> size;
	int number[size];
	
	for(int i=0; i<size ; i++)
	{
		cout<<"Number "<<(i+1) << ": ";
		cin>> number[i];
	}
	
	cout<< endl;
	for(int i= 0; i<size ; i++)
	{
		bool isitPrime= true;
		int divisor =2;
		if(number[i]<2)
			isitPrime = false;
			
		while(divisor < number[i] && isitPrime)
		{
			if(number[i] % divisor ==0)
				isitPrime = false;
			else
				divisor++;
		}
		cout<< number[i] <<" is prime number? : "<< isitPrime <<endl;
	}
	
	return 0;
}

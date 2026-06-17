#include <iostream>
using namespace std;

const int ARRAY_SIZE = 3;
int numbers[ARRAY_SIZE];

int main()
{
	for(int count =0; count< 7; count++)
	{
		numbers[count] = 100;
		cout << numbers[count] <<" ";
	}
	return 0;
}

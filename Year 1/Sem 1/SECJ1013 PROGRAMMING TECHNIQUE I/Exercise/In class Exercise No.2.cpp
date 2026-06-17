#include <iostream>
using namespace std;

int cube (int num)
{
	return num*num*num;
}

int main()
{
	int result = cube(4);
	cout << result;
	return 0;
}

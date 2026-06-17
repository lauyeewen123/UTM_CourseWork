#include <iostream>
using namespace std;
void testDefaultParam(int, int =5, double =3.5);

void testDefaultParam(int a, int b, double z){
	int u;
	a=a+static_cast<int> (2*b+z);
	u=a+b*z;
	cout<<"u= " <<a<<endl;
}
int main()
{
	testDefaultParam(3,4,5.5);
	return 0;
}

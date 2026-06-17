#include <iostream>
using namespace std;
int j= 40;

void p()
{
	int i= 5;
	static int j=5;
	i++;
	j++;
	cout<<"i: " <<i<<endl;
	cout<<"j: " <<j<<endl;
}

int main()
{
	p();
	p();
	return 0;
}

#include <iostream>
using namespace std;

class demo
{
	int data;

public:
	demo(int a) // also can write outside the class, but must initialize in class first
	{
		data = a;
	}
	
	// default constructor
	demo()
	{
		
	}
	
	void display()
	{
		cout << "Data = " << data << endl;
	}
};

int main()
{
	demo obj(60), obj2; // (obj2) This object will call default constructor
	obj.display();
	
	return 0;
}



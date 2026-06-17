#include <iostream>
using namespace std;

class complex
{
	float x,y;
public:
	
	complex()
	{
		x=0;
		y=0;
	}
	
	complex(float a)
	{
		x=a;
		y=0;
	}
	
	complex(float b, float c)
	{
		x=b;
		y=c;
	}
	
	void display()
	{
		cout <<" X = " << x<< ", Y = " << y << endl;
	}
};

int main()
{
	complex obj1, obj2(50.33), obj3(30.33,60.55);
	obj1.display();
	obj2.display();
	obj3.display();
	
}

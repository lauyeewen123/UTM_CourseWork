#include <iostream>
#include <string>
using namespace std;

const double pi = 3.142;

class Circle
{
	private:
		double radius;
	
	public:
		Circle (double r)
		{
			radius =r;
		}
		
		double getArea() const
		{
			return pi*radius*radius;
		}
};

void printArea(Circle *a)
{
	cout << "Area of circle: " << a->getArea() << endl;
}

int main()
{
	Circle obj (5.5);
	printArea(&obj);
	return 0;
}

//string name=  "objects";
//string sub= name.substr(2,3);
//cout << sub;

#include <iostream>
#include <string>
using namespace std; 

class school
{
	private:
		string name;
		int marks;
	public:
		void getdata();
		void displaydata();
		
};

void school::getdata() //:: is called scope resolution operator,means this function belong to school class.
{
	
		cout << "Enter student name: ";
		cin >> name;
		cout << "Enter student marks: ";
		cin >> marks;
		cout <<endl;	
}

void school::displaydata()
{
		cout <<"Student name: " << name << endl;
		cout <<"Student marks: " << marks << endl;	
}

int main()
{
	school student1,student2;
	student1.getdata();
	student2.getdata();
	
	cout << endl;
	
	student1.displaydata();
	student2.displaydata();
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name1, name2, num1, num2;
    
    cout << "Enter member 1 name: ";
     cin.ignore();
	getline(cin, name1);
    
    cout << "Enter memeber 1 matric number: "; 
    cin >> num1;
    //cin.ignore();
    
    cout << "Enter memeber 2 name: ";
     cin.ignore();
    getline(cin,name2);
    
    cout << "Enter member 2 matric number: ";
    cin >> num2;
    //cin.ignore();
    
	cout << "\nAssignment 1" <<endl;
	cout << "-----------------" << endl;
	cout << "Course: SECJ 1013 Programming Technique 1" <<endl;
	cout << "Section: 03";	
	cout << "\nProgram: Bachelor of Computer Science (Data Engineering)"<<endl ;	
	
	cout << "Members: " << endl;
	cout << name1 <<" (" << num1 <<")"<< endl;
	cout << name2 <<" (" << num2 <<")";
    return 0;	
}

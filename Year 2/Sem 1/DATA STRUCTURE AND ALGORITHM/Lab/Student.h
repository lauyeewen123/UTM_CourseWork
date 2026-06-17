// Lab 1 - SECJ2013 - 24251 (Student.h)
// Group Members:
// 1. LAU YEE WEN A23CS0099
// 2. GUI KAH SIN A23CS0080

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Class defintion
class Student 
{
    private:
    	string name;
    	int cwMark;
    	int feMark;
    	int total;
    
    public:
    Student (string n, int cw, int fe)
    {
    	this->name= n;
    	this->cwMark= cw;
    	this->feMark= fe;
	}
	
	int getTotalMark()
	{
		total= cwMark+ feMark;
		return total;
	}
	
	string getGrade()
	{
		if(total >= 75 && total <=100)
			return "A";			
		else if (total >= 65 && total <=74)
			return "B";
        else if (total >= 50 && total <=64) 
			return "C";
        else if (total >= 35 && total <=49)
			return "D";
        else 
			return "E";
	}
	
	void printInfo()
	{
		cout << "Name: " << this->name << "\n";
        cout << "Coursework: " << this->cwMark << "\n";
        cout << "Final Exam: " << this->feMark << "\n\n";
	}
	
	void printResult()
	{
		cout << name <<" " << getTotalMark() << " " << getGrade() <<endl;
	}
	
	void printResultFile(fstream &outfile)
	{	
    	outfile << name << " " << getTotalMark() << " " << getGrade() << endl;
	}
	
	 ~Student() {
          cout << "Destroy student object- " << this->name << "\n";
      }
};

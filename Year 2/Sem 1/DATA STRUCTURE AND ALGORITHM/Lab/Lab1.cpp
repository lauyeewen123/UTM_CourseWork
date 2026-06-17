// Lab 1 - SECJ2013 - 24251 (Lab1.cpp)
// Group Members:
// 1. LAU YEE WEN A23CS0099
// 2. GUI KAH SIN A23CS0080

#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

using namespace std;

// main function
int main() {
    const int LIST_SIZE = 10;
    Student* studList[LIST_SIZE];

    
    fstream infile("Marks.txt", ios::in);
	
    if(!infile)
    {
    	cout << "Can't open the file" <<endl;	
	}
	
	string n;
	int cw, fe;
	int count = 0;
	
	if(infile)
	{
		while (!infile.eof())
		{
			infile >> n >> cw >> fe;
			studList[count] = new Student(n, cw, fe);
			count++;
		}
			infile.close();
	}
	else
	{
		cout << "Can't open the file" <<endl;
	}

	
	fstream outfile("Results.txt", ios::out);
	if(!outfile)
    {
    	cout << "Can't open the file" <<endl;	
	}
	
	cout << "Student mark info: " << endl;
	for (int i=0; i< count ; i++)
	{
		studList[i] -> printInfo();
	}
	
	cout << "Print and save results to file: " << endl;
	for (int i=0; i< count ; i++)
	{
		studList[i] -> printResult();
		studList[i] -> printResultFile(outfile);
		delete studList[i];
	}
	
	outfile.close();
    return 0;
}

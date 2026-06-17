//LAU YEE WEN A23CS0099
#include <iostream>
using namespace std;

//function prototype
void getInput(double &,double &,double &);
void dispTier(int);
double calcAverage(int ,double);
void dispSummary(int);

//Task 1
void getInput(double &score_q1,double &score_q2,double &score_q3)
{
	do
	{
		cout <<"Q1 mark: ";
		cin>> score_q1;
	} while((score_q1<0|| score_q1 >100));
	
	do
	{
		cout <<"Q2 mark: ";
		cin>> score_q2;
	} while((score_q2<0|| score_q2 >100));
	
	do
	{
		cout <<"Q3 mark: ";
		cin>> score_q3;
	} while((score_q3<0|| score_q3 >100));
}

//Task 2
void dispTier(int total)
{
	int tier=0;
	if(total>=75 && total<=100)
		tier =1;
		
	else if(total>= 40 && total<75)
		tier =2;
		
	else 
		tier =3;
	cout<<"Tier    : Tier "<<tier;
}

//Task 3
double calcAverage(int num_students,double total)
{
	double avrg = total/num_students;
	return avrg;
}

//Task 4
void dispSummary(int total)
{
	cout << endl;
	cout << "<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>" <<endl;
	cout << "Total marks: " << static_cast<int>(total);
	cout << endl;
	dispTier(total);
}

int main()
{
	string name;
    string highest_name;
	string lowest_name;
	double total_marks = 0;
	double total=0;
	double  q1,q2,q3;
	double lowest= 99999;
	double highest = 0;
	int num_student = 0;
	
	do
	{
		
		cout << "\n\n<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>" << endl;
		cout << "Name : ";
		getline(cin,name);	
		
		if(name == "\0")
        	break;
        else
        	num_student++ ;
		
		getInput(q1,q2,q3);
		
		total= (q1/100*35)+ (q2/100*25)+ (q3/100*40);
		
		if(total<lowest)
		{
			lowest = total;
			lowest_name = name;
		}
			
		if(total>highest)
		{
			highest = total;
			highest_name = name;
		}
		
		total_marks += total;
		dispSummary(total);
		
		cin.ignore();

	} while (name !="\0");
	
	cout << "\n<<<<<<< RESULTS ANALYSIS >>>>>>>>" <<endl;
	cout << "Lowest mark : " << static_cast<int>(lowest) << "("  << lowest_name <<")" <<endl; 
	cout << "Highest mark: " << static_cast<int>(highest) << "(" << highest_name <<")" <<endl; 
	cout << "Average for " << num_student <<" students:" << static_cast<int> (calcAverage(num_student, total_marks)) <<endl;
	
	return 0; 

}

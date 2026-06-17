//LAU YEE WEN A23CS0099
#include <iostream>
using namespace std;

//function prototype
void getInput(int &, int &, int &);
void dispTier(int);
int calcAverage(int ,int);
void dispSummary(int);

//Task 1
void getInput(int &score_q1,int &score_q2, int &score_q3)
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
int calcAverage(int num_students,int total)
{
	int avrg = total/num_students;
	return avrg;
}

//Task 4
void dispSummary(int total)
{
	cout << endl;
	cout << "<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>" <<endl;
	cout << "Total marks: " << total;
	cout << endl;
	dispTier(total);
}

int main()
{
	string name;
    string highest_name;
	string lowest_name;
	int total_marks = 0;
	int total=0;
	int  q1,q2,q3;
	int lowest= 99999;
	int highest = 0;
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
		
		total= (q1*35/100)+ (q2*25/100)+ (q3*40/100);
		
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
	cout << "Lowest mark : " << lowest<< " ("  << lowest_name <<")" <<endl; 
	cout << "Highest mark: " << highest << " (" << highest_name <<")" <<endl; 
	cout << "Average for " << num_student <<" students:" << calcAverage(num_student, total_marks) <<endl;
	
	return 0; 

}

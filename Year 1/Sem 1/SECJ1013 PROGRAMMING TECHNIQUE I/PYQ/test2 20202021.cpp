#include <iostream>
using namespace std;

void dispStatus(int);
void getInput(int &, int &, int &, int &);
void dispOutput(int );
int calcAverage(int, int);


void dispStatus(int active_cases)
{
	cout <<"Status : ";
	
	if(active_cases>40)
		cout <<"Red zone";
	else if(active_cases>=21 && active_cases <=40)
		cout << "Orange zone";
	else if(active_cases>=1 && active_cases <=20)
		cout << "Yellow zone";
	else
		cout <<"Green zone";
}

void getInput(int &num_cases, int &new_cases, int &tot_death, int &tot_rec)
{
	cout <<"Total cases : ";
	cin >> num_cases;
	cout <<" New cases : ";
	cin >> new_cases;
	cout << "Total death : ";
	cin >> tot_death;
	cout << "Total recovered: ";
	cin >>  tot_rec;
}

void dispOutput(int active_cases)
{
	dispStatus(active_cases);
}

int calcAverage(int num_states, int tot_active)
{
	int avrg = tot_active/num_states;
	return avrg;
}

int main()
{
	string name;
	int num_cases,new_cases,tot_death,tot_rec;
	int total= 0;
	int highest= -99999;
	int numState =0;
	string highest_state;
	string continueloop;
	
	do
	{
		cout << "\n<<<<<<<<<< DATA >>>>>>>>>>>" <<endl;
		cout << "State name: ";
		getline(cin,name);
		numState++;
		
		getInput(num_cases,new_cases,tot_death,tot_rec);
		
		int active_cases = num_cases + new_cases - tot_death - tot_rec;
		cout << endl;
		cout << "<<<<<<<<<<< SUMMARY >>>>>>>>>>>>" <<endl;
		cout <<"Active cases : " << active_cases << endl;
		
		dispStatus(active_cases);
			
		if(active_cases>highest)
		{
			highest = active_cases;
			highest_state = name;
		}	
		
		total= total+ active_cases;
		cin.ignore();
		cout << "\n\nPress <ENTER> to continue... ";
		getline(cin,continueloop);

		if (continueloop !="\0")
			break;
			
	} while (continueloop == "\0"); 
	
	cout << "\n<<<<<<<<<<<< ACTIVE CASES >>>>>>>>>>>>>" <<endl;
	cout << "Total: " << total << endl;
	cout << "Highest: " << highest << " (" << highest_state <<")";
	cout << "\nAverage for " << numState << " states : " << calcAverage(numState,total);
		
	return 0;
}

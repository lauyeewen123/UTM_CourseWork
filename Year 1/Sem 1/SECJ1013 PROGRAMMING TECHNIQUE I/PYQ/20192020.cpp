//LAU YEE WEN A23CS0099
#include <iostream>
using namespace std;

//function prototype
double getAmount();
void times(double &,  double &);
bool validTime(double);
void mealsAllowance(double &, double &, double &);

// Task 1
double getAmount()
{	
	double spent;
	cout <<"Please enter the amount spent : ";
	cin >> spent;
		
	while(spent ==0 || spent <0) //not accept zero and negative number for the input
	{
		cout <<"Amount must be greater than 0. " <<endl;
		cout <<"Please enter the amount spent : ";
		cin >> spent;
		cout <<endl;
	}
	return spent;
}

//Task 2
void times(double &pi, double &po)
{
	cout << "Please enter the punch in time (HH.MM) :  ";
	cin >> pi;
	while (validTime(pi)== false)
	{
		cout << "Punch in time must be between 00.00 and 23.59. " <<endl;
		cout << "\nPlease enter the punch in time (HH.MM) :  ";
		cin >> pi;
	}
	
	cout << "Please enter the punch out time (HH.MM) :  ";
	cin >> po;
	while (validTime(po)== false)
	{
		cout << "Punch out time must be between 00.00 and 23.59. "<<endl;
		cout << "\nPlease enter the punch out time (HH.MM) :  ";
		cin >> po;
	}
	
	while (pi>po)
	{
		cout << "Invalid inputs!!" <<endl;
		cout << "\nPlease enter the punch in time (HH.MM) :  " ;
		cin >> pi;
		while (validTime(pi)== false)
		{
			cout << "Punch in time must be between 00.00 and 23.59. "<<endl;
			cout << "\nPlease enter the punch in time (HH.MM) :  ";
			cin >> pi;
		}
		
		cout << "Please enter the punch out time (HH.MM) :  ";
		cin >> po;
		while (validTime(po)== false)
		{
			cout << "Punch out time must be between 00.00 and 23.59. "<<endl;
			cout << "\nPlease enter the punch out time (HH.MM) :  ";
			cin >> po;
		}
	}
}
	
//Task 3
bool validTime(double time) 
{
	int hours = static_cast <int> (time);
	double minutes = time-hours;
	
	if ((hours <0 )|| (hours >23 ) ||( minutes < 0.00 )|| (minutes >0.59))
		return false;
	else
		return true;
}

//Task 4
void mealsAllowance(double &E, double &GA, double &AA)
{
	double pi,po, breakfast_spent, lunch_spent, dinner_spent;
//	E=0;
//	GA =0;
//	AA=0;
	//constant variables
	const int breakfast = 5; 
	const int lunch = 7;
	const int dinner = 7;
	
	times(pi,po);
	
	if (pi <7.00)
	{
		cout <<"\n:: Breakfast :: " <<endl;
		breakfast_spent = getAmount();
		E+= breakfast_spent;
		GA+= breakfast;
		
		if (breakfast > breakfast_spent)
			AA+= breakfast_spent;
		else
			AA+= breakfast;
	}
	
	if (po > 12.00)
	{
		cout <<"\n:: Lunch :: " <<endl;
		lunch_spent = getAmount();
		E+= lunch_spent;
		GA+= lunch;
		
		if (lunch > lunch_spent)
			AA+= lunch_spent;
		else
			AA+= lunch;
	}
	
	if (po > 18.00)
	{
		cout <<"\n:: Dinner :: " <<endl;
		dinner_spent = getAmount();
		E+= dinner_spent;
		GA+= dinner;
		
		if (dinner > dinner_spent)
			AA+= dinner_spent;
		else
			AA+= dinner;
	}	
}

int main()
{
	int days;
	int count =0;
	double E=0 , GA=0 , AA=0 , EA, AS;
	cout << "Please enter the number of working days : ";
	cin >> days;
		
	while(count < days)
	{
		cout <<"\nDay " << count+1 <<": " <<endl;
		mealsAllowance(E, GA, AA);
		count++;
	}

	cout << "\nTotal expenses : RM" << E <<endl;
	cout << "Total given allowance     : RM" << GA <<endl;
	cout << "Total allowable allowance : RM" << AA <<endl;
	
	EA = E-AA;
	AS = GA-AA;
	
	cout << "\nExtra amount paid by employee   : RM" <<EA <<endl;
	cout << "Total save by employer          : RM" <<AS <<endl;
	
	return 0;
} 







//LAU YEE WEN
#include <iostream>
using namespace std;

int main()
{
	int year;
	const int MONTHS =12;
	int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
	cout<<"Enter the year: " ;
	cin>>year;
	
	for (int i=0; i<MONTHS; i++)
	{
		cout<<"Month " << (i+1)<<" ";
		
		switch(i)
		{
			case 0: cout<<"January";
					break;
			case 1: cout<<"February";
					break;
			case 2: cout<<"March";
					break;
			case 3: cout<<"April";
					break;
			case 4: cout<<"May";
					break;
			case 5: cout<<"June";
					break;
			case 6: cout<<"July";
					break;
			case 7: cout<<"August";
					break;
			case 8: cout<<"September";
					break;
			case 9: cout<<"October";
					break;
			case 10: cout<<"November";
					break;
			case 11: cout<<"December";
					break;
			deafult: cout<<"January";
					break;
		}
		if(year%4 == 0)
			days[1]=29;
		
		cout<<" has " << days[i] <<" days."<<endl;
	}
	return 0;
}

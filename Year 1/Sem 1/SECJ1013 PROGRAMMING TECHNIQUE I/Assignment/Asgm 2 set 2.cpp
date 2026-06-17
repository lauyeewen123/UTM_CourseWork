#include <iostream>
using namespace std;

int main()
{
	int num;
	cout<<"Welcome to the Food Ordering System" <<endl;
	cout<<" 1. Pizza - $10" <<endl;
	cout<<" 2. Burger - $5" << endl;
	cout<<" 3. Sandwich - $7" << endl;
	cout<<" Enter the number of the item you want to order: ";
	cin >> num; 
	cout << "Your total bill is: ";
	
	if(num==1)
		cout<<"$10";
	else if (num==2)
		cout <<"$5";
	else if(num ==3)
		cout <<"$7";
		
	return 0;
}

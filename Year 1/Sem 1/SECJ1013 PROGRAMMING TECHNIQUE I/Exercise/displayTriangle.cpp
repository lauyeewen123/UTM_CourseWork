#include <iostream>
using namespace std;
void displayPyramid (int = 8); 

int main(){
	displayPyramid();
	cout << "\nMerry Christmas!!!" ;
	return 0;
}
void displayPyramid (int n)
{
		for (int i=1; i<= n; i++) 
		{
			for (int j=1; j<= 2*n -1;j++)
			{
				if(j>= n- (i-1) && j<= n+ (i-1))
					cout << "*";
				else
					cout << " "; 
			}
			cout << endl;
		}	
		
	    for (int i=1; i<4; i++) 
		{
			for (int j=1 ; j<n; j++)
			{
				cout << " ";
			}
			cout << "*" << endl;
		}	
}

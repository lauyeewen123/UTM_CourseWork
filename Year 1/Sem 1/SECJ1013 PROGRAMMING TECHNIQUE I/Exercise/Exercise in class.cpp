#include <iostream>
#include <string>
using namespace std;

int main(){	
	int num_subject, mark;
	string subject;
		
	cout << "Please enter your number of subject: ";
	cin >> num_subject;
	
	while (num_subject>0)
	{
		cout << "\nPlease enter your subject name: ";
		cin.ignore();
		getline(cin,subject);
		
	 	cout << "Please enter your mark: ";
		cin >> mark;
				
		if(mark >=80)
			cout << "Your GPA in this " << subject << " is 4.0"<<endl;
		else
			cout << "Work Hard"<<endl;
			
		num_subject--;		
	}
	return 0;
}

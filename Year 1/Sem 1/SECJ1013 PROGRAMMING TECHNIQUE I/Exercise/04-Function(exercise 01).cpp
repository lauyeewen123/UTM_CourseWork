#include <iostream>
#include <cctype>
using namespace std;

int main(){
	char ch;
	cout << "Enter any character: ";
	cin.get(ch);
	
	if(isdigit(ch))
		cout << "digit" ;
		
	else if (isalpha(ch))
		cout << "letter" ;
	else
		cout << "special character" ;
	
	return 0;
}

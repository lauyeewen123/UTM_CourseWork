//LAU YEE WEN A23CS0099
#include <iostream>
#include <cctype>
using namespace std;

void displayMenu();
void countWords();
void calcElecRest();
double calc_Q(double);

const int SIZE =100;

int main()
{
	displayMenu();
	return 0;
}
void displayMenu()
{
	int choice;
	cout << "::MID TERM TEST SYSTEM MENU::" <<endl;
	cout << " (1) Words count calculator " <<endl;
	cout << " (2) Electric charges calculator " <<endl;
	cout << " (3) Quit" <<endl;
	
	cout << "Your choice >> ";
	cin >> choice;
	
	switch(choice)
	{
		case 1 : countWords();
				 cout << endl;
				 break;
		case 2 : calcElecRest();
				cout <<endl;
				break;
		default : cout << "Thank you for using our system... ";
	}
}

void countWords()
{
	int num = 1;
	int i=0;
	bool answer= true;
	char words[SIZE];
	cout << "::WORDS COUNT CALCULATOR::" <<endl;
	cout <<endl;
	cout << "Enter a string : " ;
	cin.ignore();
	cin.getline(words,SIZE);
	
	cout << "\n\nList of Words: " <<endl;
	
    do{
        cout<<"\tWord "<<num<<" >> ";
        while(words[i]!=' ')
		{
            if((!ispunct(words[i]))&&(!isalpha(words[i]))&&(!isdigit(words[i])))
			{
                answer=false;
                break;
            }
            
            if(isalpha(words[i]))
			{
                words[i]= tolower(words[i]);
                cout<< words[i];
            }
            i++;
        }
        do
		{
            i++;
        } while((words[i]==' ')||(!isalpha(words[i])));
        num++;
        cout<<endl;
    } while(answer);
	
	cout << "The number of words = " << num-1 <<endl;
}

void calcElecRest()
{
	double power, voltage,time, current, charge;
	cout << "::ELECTRIC CHARGES CALCULATOR::" <<endl <<endl;
	cout << "Please enter the power (P) in Watts and the voltage (V) in kilovolts" <<endl;
	
	do
	{
		cout << "\nPower (P) =";
		cin >> power;
		cout << "Voltage (kV) =";
		cin >> voltage;
		
		if ((voltage<0 )|| (power <0))
			cout << "Invalid input, Please try again !";
	} while ((power<0 )|| (voltage <0));
	
	current = power/(voltage*1000);
	charge=calc_Q(current);
	
	cout<<"\nPower, P = "<<power<<" watts"<<endl;
    cout<<"Voltage, V = "<<(voltage*1000)<<" volts"<<endl;
    cout<<"Electric current, I = "<<current<<" amperes"<<endl;
    cout<<"Electric charge, Q = "<<charge<<" coulombs"<<endl;
}

double calc_Q(double current)
{
	double time;
	cout << "Enter the time of current flow, t in minutes = ";
	cin >> time;
	double charge = current*(time*60);
	
	return charge;
}

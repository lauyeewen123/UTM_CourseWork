//LAU YEE WEN A23CS0099
//CHERYL CHEONG KAH VOON A23CS0060
#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 10; //declare constant
string title[MAX_BOOKS];
string author[MAX_BOOKS];
int years[MAX_BOOKS];
int bookCount = 0;

//function prototype
void displayMainMenu();
void addBook();
void displayLibrary();
void searchByTitle();

int main()
{
    int choice;
    do
    {
        displayMainMenu();
	    cout<<"Enter your choice: ";
	    cin >> choice;
        switch (choice)
        {
            case 1: addBook(); break;
            case 2: displayLibrary(); break;
            case 3: searchByTitle(); break;
            case 4: cout<< "\nGoodBye!"; break;
            default: cout <<"\nInvalid choice. Please enter again.\n\n"; break;
        }

    } while (choice !=4);
	
	return 0;
}

void displayMainMenu()
{
		cout<<"<<<<<Library Management System>>>>>"<<endl;
		cout<<"==================================="<<endl;
		cout<<"1. Add a Book"<<endl;
		cout<<"2. Display Library"<<endl;
		cout<<"3. Search by Title"<<endl;
		cout<<"4. Quit\n"<<endl;
}

void addBook()
{
    if(bookCount< MAX_BOOKS)
    {
        cout<<"\nEnter book title: ";
        cin.ignore();
        getline(cin,title[bookCount]);
        
        cout<<"Enter author name: ";
        cin >> author[bookCount];
        
        cout << "Enter publication year: ";
        cin >> years[bookCount];
        
		cout<<endl<<endl;
        cout<< "Book added succeddfully!\n\n";
        bookCount++;
    }
    else 
        cout<<"Library is full. Cannot add more books.\n" ;
   
}

void displayLibrary()
{
    if(bookCount == 0)
        cout << "\nLibrary is empty.\n\n";
    else
    {
        cout << "\nLibrary Contents: "<<endl;
        cout << "====================" << endl;
        for(int i=0; i<bookCount ; i++)
        {
        	cout<<endl;
            cout << "Title: " << title[i] << endl;
            cout << "Author: " << author[i] << endl;
            cout << "Year: " << years[i] << endl;
        }
        cout<< endl;
    }
}

void searchByTitle()
{
    string searchtitle;
    cout <<"\nEnter the title to search: ";
    cin.ignore();
    getline(cin,searchtitle);

    bool found = false;
    
    for (int i=0; i<bookCount ; i++)
    {
         if(title[i]== searchtitle)
         {
            cout << "\nBook found:"<<endl;
            cout << "===============" <<endl;
            cout << "Title: " << title[i] << endl;
            cout << "Author: " << author[i] << endl;
            cout << "Year: " << years[i] << endl << endl;
            found = true;
            break;
         }
    }
    
    if (found==false)
        cout <<"\nBook not found in the library.\n\n" << endl;   
}


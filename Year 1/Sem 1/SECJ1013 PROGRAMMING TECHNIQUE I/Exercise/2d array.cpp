#include <iostream>
#include<string>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void display(string[][COLS],int );//function prototype

int main()
{
    string WHATtoEAT[ROWS] [COLS]= {{"PASTA","CHICKEN CHOP","LAKSA"}, {"BURGER", "CAKE","HOTPOT"}};
    cout<<"What I eat in this weekend?"<<endl;

    display(WHATtoEAT,ROWS);
    return 0;
}

void display(string WHATtoEAT[][COLS],int ROWS)
{
    for(int i=0; i<ROWS ;i++)
    {
        for(int j =0; i<COLS; j++)
        {
            if(i==0)
                cout<<"Saturday eat ";
            else
                cout <<"Sunday eat ";
                
        	cout<< WHATtoEAT[i][j];
        }
        cout <<endl;
    }
}



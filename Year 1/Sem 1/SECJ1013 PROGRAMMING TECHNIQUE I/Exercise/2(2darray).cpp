#include<iostream>
#include <iomanip>
using namespace std;

const int ROWS=3;
const int COLS=3;

void add(int[][COLS], int [][COLS]);

void add(int a[ROWS][COLS],int b[ROWS][COLS])
{
	int total=0;
	for (int i=0;i< ROWS; i++)
	{
		for(int j=0; j<COLS; j++)
		{
			total = b[i][j] - a[i][j];
			cout << setw(3)<<total;
		}
		cout<<endl;
	}
}

int main()
{
	int a[ROWS][COLS]= {{1,2,3},{1,2,3},{1,2,3}};
	int b[ROWS][COLS]= {{3,4,5},{3,4,5},{3,4,5}};
	add(a,b);
	cout <<endl;
	return 0;
}

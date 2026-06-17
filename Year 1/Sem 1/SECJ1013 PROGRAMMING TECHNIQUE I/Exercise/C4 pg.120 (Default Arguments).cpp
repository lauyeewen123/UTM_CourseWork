#include <iostream>
using namespace std;
void displayStars(int =10, int =1); //default value

int main()
{
	displayStars();
	cout << endl;
	displayStars(5); //(5,1) use default value for rows
	cout << endl;
	displayStars(7,3); //7 for cols and 3 for rows
	return 0;
}

void displayStars(int cols, int rows)
{
	for(int down =0; down< rows; down++) //control the row
	{
		for (int across = 0; across < cols; across++) //control the column
			cout<< "*";
		cout << endl;
	}
}

#include <iostream>
using namespace std;

int main()
{
	
	int x,y;
	int count = 1;
	int month = 12, day = 14;
	for (x=0; x<= month ; x++)	
	{
		//cout << "\n\ncount: " <<count;
		for( y=x; y<= day; y++)
		{
			cout << "\n\ncount: " <<count;
			cout << "\tx = " << x << " y = " << y;
			count++;
		}
	}
	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	int num[5]={2,4,6,8,10};
	int lowest= num[0];
	int highest= num[0];
	highest =num[0];
	for(int i=0; i<5;i++ )
	{
		if(num[i]>highest)
			highest= num[i];
		if(num[i]<lowest)
			lowest= num[i];
	}
	cout <<"The highest number is : " << highest<<endl;
	cout <<"The lowest number is : " << lowest;
	return 0;
}

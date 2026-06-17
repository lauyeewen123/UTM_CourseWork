#include <iostream>
#define MAX_WEIGHT 3.0
using namespace std;

float get_Price();
float get_Weight();
void postage (float &, float);

int main()
{
	float weight = 0;
	float price = 0;
	
	weight = get_Weight();
	price = get_Price();
	
	cout << "Price not including postage = " <<price << "\n\n";
	postage (price, weight);
	
	cout << "Total price including postage = " << price << "\n";
	
	return 0;
}

float get_Price()
{
	float p = 0;
	
	cout << "\n";
	while ((p==0) || (p<0))
	{
		cout <<"Item price (RM) : ";
		cin >> p;
	}
	
	return p;
}

float get_Weight()
{
	float w =0;
	do 
	{
		cout << "Item weight (not more than 3 kg) : ";
		cin >> w;
	} while ((w<=0) || (w> MAX_WEIGHT));
	
	return w;
}

void postage (float &p, float w)
{
	float post =0;
	
	if(w>2)
	{
		post = 10;
	}
	else if (w>=1)
	{
		post = 7;
	}
	else
	{
		post = 4;
	}
	
	cout << "Postage cost = " << post << "\n" ;
	p+= post;
}

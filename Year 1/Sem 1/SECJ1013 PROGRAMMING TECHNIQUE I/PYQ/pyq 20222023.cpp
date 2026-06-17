//LAU YEE WEN A23CS0099
#include <iostream> 
using namespace std;

//function prototype
void readQty(int&,int&,int&);
void displayHighProd(double,double,double);
double calcAvg(int, double);
void summaryCom(double, double, double, double);

//task 1
void readQty(int &qtyA, int &qtyB, int &qtyC) 
{
	do
	{
		cout<< "Product A: ";
		cin>> qtyA;
	} while(qtyA<0 || qtyA>100);
	
	do
	{
		cout<< "Product B: ";
		cin>> qtyB;
	} while(qtyB<0 || qtyB>100);
	
	do
	{
		cout<< "Product C: ";
		cin>> qtyC;		
	} while(qtyC<0 || qtyC>100);	
}

//task 2
void displayHighProd(double comm_A, double comm_B , double comm_C)
{
	char highest;
	cout<<"\nHighest commission - Product ";
	if(comm_A>comm_B)
	{
		if(comm_A>comm_C)
		{
			highest = 'A';
			cout << highest <<": RM" << comm_A;
		}
			
		else
		{
			highest ='C';
			cout << highest <<": RM" << comm_C;
		}	
	}
		
	else
	{
		if(comm_B> comm_C)
		{
			highest='B';
			cout << highest <<": RM" << comm_B;	
		}
		else 
		{
			highest ='C';
			cout << highest <<": RM" << comm_C;
		}
	}	
}

//task 3
double calcAvrg (int num_agent, double totalComAllAgent)
{
	double avrg= totalComAllAgent/num_agent;
	return avrg;
}

//task 4
void summaryCom(double commA, double commB, double commC, double total)
{
	cout << "-----------------SALES SUMMARY-------------------"<<endl;
	cout << "Total of commission for three products: RM" << total;
	displayHighProd(commA,commB,commC);
	cout<<endl;
}

//task 5
int main()
{
	
	string lowestTotalname;
	string highestTotalname;
	string highAname;
	string highBname;
	string highCname;
	
	double totalAllAgentComm=0;
	double lowestTotal= 99999; 
	double highestTotal= 0; 
    double highestA=0; 
    double highestB=0;
	double highestC=0;
	string name;
	int numAgent= 0;
	int A,B,C;
	
	do
	{
		cout <<"-----------------AGENT---------------"<<endl;
		cout <<"Agent Name: ";
		getline(cin,name);
		
		if (name=="\0")
			break;
		else
			numAgent++;
	
		readQty(A,B,C); // call task 1
		
		// calculate commision
		double totalComm,comm_A,comm_B,comm_C;
		comm_A = (A*150*0.025);
		comm_B = (B*300*0.05);
		comm_C = (C*450*0.1);
		totalComm = comm_A+ comm_B+ comm_C;
		
		summaryCom(comm_A,comm_B,comm_C,totalComm);// call task 4
		cout<<endl;
		
		totalAllAgentComm += totalComm;
		
		if(totalComm > highestTotal)
		{
			highestTotal= totalComm;
			highestTotalname = name;
		}
		
		if(totalComm < lowestTotal)
		{
			lowestTotal= totalComm;
			lowestTotalname = name;
		}
		
		if(comm_A> highestA)
		{
			highestA= comm_A;
			highAname = name;
		}
		
		if(comm_B> highestB)
		{
			highestB= comm_B;
			highBname = name;
		}
		
		if(comm_C> highestC)
		{
			highestC= comm_C;
			highCname = name;
		}
		cin.ignore();
		
	} while(name!="\0");
		
		cout <<"------------------SALES ANALYSIS-------------------" <<endl;
		cout <<"Lowest commission for three products: RM" <<lowestTotal <<" (" <<lowestTotalname<<")"<<endl;
		cout << "Highest commission for three products: RM" << highestTotal <<" (" <<highestTotalname<<")"<<endl;
		cout << "Highest commission for Product A: RM" <<highestA << " (" <<highAname << ")"<<endl; 
		cout << "Highest commission for Product B: RM" <<highestB << " (" <<highBname << ")"<<endl; 
		cout << "Highest commission for Product C: RM" <<highestC << " (" <<highCname << ")"<<endl; 
		cout << "Total of commission for " << numAgent<<" agents: RM" << totalAllAgentComm<<endl;
		cout << "Average commission for " <<numAgent << " agents: RM" << calcAvrg(numAgent,totalAllAgentComm)<<endl;
		
		return 0;  

}

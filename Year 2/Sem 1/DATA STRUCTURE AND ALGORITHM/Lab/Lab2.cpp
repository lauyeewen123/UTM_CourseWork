// Lab 2 - SECJ2013 - 24251 (Lab2.cpp)
// Group Members:
// 1. LAU YEE WEN A23CS0099
// 2. GUI KAH SIN A23CS00

#include <iostream>
#include <string>

using namespace std;

void printStar(int n) {
    if(n>0)
    {
     	cout << "*";
     	printStar(n-1); //recursive call
	}
}

void printNum(int n, int i=1) {
    if(i <= n) {
         cout << i << " - ";
         printStar(i);
         cout << endl;
         printNum(n, i+1); //recursive call
     }
}

int totalOdd(int list[], int n) {
    if(n==0)
    	return 0; // base case
    	
	int num= list[n-1];
	int total= totalOdd(list, n-1); // Recursive call
    
    if (num % 2 != 0) 
	{
        cout << num << " ";
        total = total+num ;
    }
    return total;
}

// Main function
int main(int argc, char *argv[])
{
    printNum(6);

    cout << "\n\n";

    int num[6] = {0, 1, 2, 3, 4, 5};
    int result = totalOdd(num, 6);
    cout << "= " << result << endl;
    return 0;
}


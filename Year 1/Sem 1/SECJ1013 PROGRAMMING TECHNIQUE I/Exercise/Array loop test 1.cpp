#include <iostream>
using namespace std;
const int ARRAY_SIZE = 5;
int main(){
    int numbers[ARRAY_SIZE];

    for(int count=0;count<5;count++){
        numbers[count]=99;
        cout<<numbers[count];
        cout<<" "; 
        numbers[2]=999;
        cout<<numbers[2];
        numbers[3]=888248;
        cout<<" ";
        cout<<numbers[3];
        cout<<" ";
        //cout<<count<<endl;

    }
    return 0;
}

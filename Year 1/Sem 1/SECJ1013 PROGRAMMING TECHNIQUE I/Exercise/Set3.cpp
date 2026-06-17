#include <iostream>
using namespace std;
int main(){
	int i = 25;
	while (i >0 ) {
		for(int j=i ; j>0; j-=5) {
			if((i+j)%4 !=0)
			continue;
			else{
				cout << "j= " << --j << endl;
				cout << "i= " << i << endl;	}
}
i/= 2;
} 
return 0; }

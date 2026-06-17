//// Program 2.0
//#include <iostream>
//using namespace std;
//class Box {
//public:
//// Constructor definition
//Box(double l = 2.0, double b = 2.0, double h = 2.0)
//{ length = l;
//breadth = b;
//height = h;
//cout <<"Initializing box with "
//<< length << breadth << height << endl;
//}
//double getVolume()
//{ return length * breadth * height; }
//int compare(Box box)
//{ return this->getVolume() == box.getVolume(); }
//private:
//double length; // Length of a box
//double breadth; // Breadth of a box
//double height; // Height of a box
//};
//int main(void)
//{
//	Box Box1(3.3, 1.2); // Declare box1
//	Box Box2(1.2, 2.0, 3.3); // Declare box2
//	Box Box3; // Declare box3
//	if (Box1.compare(Box2)) 
//	{
//		cout << "Box2 has the same volume with Box1" <<endl;
//	}
//	else
//		cout << "Box2 does not has the same volume with Box1"
//			<< endl;
//	return 0;
//}

//Program 4.0
#include <iostream>
#include <string>
using namespace std;
int main()
{
string w1 = "Have a nice day";
string w2(3, '%');
string w3("Ali");
//Append a single character (,) to w1
w1 += ",";
cout << w1 << endl;
//Insert w2 into w1 before the word "day"
w1.insert(12,w2);
cout << w1 << endl << w2 << endl;
//Append w3 to w1
w1.append(w3);
cout << w3 << endl << w1 << endl;
//Display the length of w1
cout << "The length of w1 = " << w1.length()<< endl;

//Replace a substring "li" in w3 with "nuar"
//w3.replace((w3.substr(1,2)),"nuar");
w3.replace( w3.find("li"), 2, "nuar" );
cout << w3 << endl;
return 0;
}

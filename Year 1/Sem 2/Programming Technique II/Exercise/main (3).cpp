// ? EXERCISE 1: INTRODUCTION TO CLASSES AND OBJECTS

// Programming Technique II
// Semester 2, 2023/2024

// Section: 01
// Member 1's Name: LAU YEE WEN  Location: ____Melaka________ (i.e. where are you currently located)
// Member 2's Name: GUI KAH SIN   Location: ____UTM________
//
// Date and time of pair programming sessions:
//   _________  (Date, time and estimate duration)
//   _________  (Date, time and estimate duration)
// 
// Video link:
//   _________  

// ? Notes: Choose the debug mode "Console Program" to run the program.

#include <iostream>
#include <string>

using namespace std;

class Subject
{
	std::string name, code;
	int score;
	
public:
	//parameterized constructor
	Subject(std::string n, std::string c, int s)
	{
		name = n;
		code = c;
		score = s;
	}
	
	//default constructor
	Subject()
	{
		
	}
	
	//destructor
	~Subject()
	{
		
	}
	
	//Accessors
	std::string getName() const
	{
		return name;
	}
	
	std::string getCode() const
	{
		return code;
	}
	
	int getScore() const
	{
		return score;
	}
	
	//Mutators
	void setName(std::string n)
	{
		name = n;
	}
	
	void setCode(std::string c)
	{
		code = c;
	}
	
	void setScore(int s)  
	{
		score = s;
	}
	
	//Additional accessor methods
	std::string determineGrade(int score) const
	{
		if (score >= 90 && score <= 100)
			return "A+";
		else if (score >= 80 && score <= 89)
			return "A";
		else if (score >= 75 && score <= 79)
			return "A-";
		else if (score >= 70 && score <= 74)
			return "B+";
		else if (score >= 65 && score <= 69)
			return "B";
		else if (score >= 60 && score <= 64)
			return "B-";
		else if (score >= 55 && score <= 59)  // Corrected range
			return "C+";
		else if (score >= 50 && score <= 54)
			return "C";
		else if (score >= 45 && score <= 49)
			return "C-";
		else if (score >= 40 && score <= 44)
			return "D+";
		else if (score >= 35 && score <= 39)
			return "D";
		else if (score >= 30 && score <= 34)
			return "D-";
		else 
			return "E";
	}
	
	double determineGradePoint(int score) const
	{
		std::string grade = determineGrade(score);
		if (grade == "A+" || grade == "A")
			return 4.00;
		else if (grade == "A-")
			return 3.67;
		else if (grade == "B+")
			return 3.33;
		else if (grade == "B")
			return 3.00;
		else if (grade == "B-")
			return 2.67;
		else if (grade == "C+")
			return 2.33;
		else if (grade == "C")
			return 2.00;
		else if (grade == "C-")
			return 1.67;
		else if (grade == "D+")
			return 1.33;
		else if (grade == "D")
			return 1.00;
		else if (grade == "D-")
			return 0.67;
		else if (grade == "E")
			return 0.00;
	}
	
	double determinePointEarned(int creditHour,int score) const  
	{
		return determineGradePoint(score) * creditHour; 
	}
};

int main()
{
	std::string name, code;
	int score;
	
	cout << "Enter the following data: " << endl;
	cout << "  Subject name => ";
	getline(cin, name);
	cout << endl;

	cout << "  Subject code => ";
	getline(cin, code);
	cout << endl;

	cout << "  Score earned => ";
	cin >> score;
	cout << endl;

 	// Create object
    Subject subject(name, code, score);
    
    int creditHour = code.back() - '0'; // Extracting credit hour from the last digit of the code

	cout << "THE RESULT" << endl
		 << endl;

	cout << "Subject Code : " << subject.getCode() << endl;
	cout << "Subject Name : " << subject.getName() << endl;
	cout << "Credit Hour  : " << creditHour << endl;
	cout << "Score Earned : " << subject.getScore() << endl;
	cout << "Grade Earned : " << subject.determineGrade(score) << endl;
	cout << "Grade Point  : " << subject.determineGradePoint(score) << endl;
	cout << "Point Earned : " << subject.determinePointEarned(creditHour,score) << endl;
	cout << endl;

	system("pause");

	return 0;
}


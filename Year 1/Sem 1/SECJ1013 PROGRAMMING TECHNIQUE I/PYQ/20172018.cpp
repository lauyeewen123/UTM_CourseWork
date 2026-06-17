#include <iostream>
#include <iomanip>
using namespace std;


void readScores(string name[], int score[] )
{
	for (int i=0; i<10; i++)
	{
		cout << "Enter the player" << i+1 << " 's name and scores: ";
		cin >> name[i] >> score[i];
	}
}

int getHighestScore(int score[])
{
	int highest = score[0];
	int highest_index = 0;
	
	for (int i=0; i<10; i++)
	{
		if (score[i] > highest)
		{
			highest = score[i];
			highest_index = i;
		}
	}
	return highest_index;
}

int getLowestScore(int score[])
{
	int lowest = score[0];
	int lowest_index = 0;
	
	for (int i=0; i<10; i++)
	{
		if (score[i] < lowest)
		{
			lowest = score[i];
			lowest_index = i;
		}
	}
	return lowest_index;
}

double averageScore(int score[])
{
	double total =0;
	for (int i=0; i<10; i++) 
	{
		total += score[i];
	}
	double avrg = total/10;
	return avrg;
}

int main()
{
	string name[10];
	int scores[10];
	readScores(name,scores);
	
	cout << "\n\nPLAYER'S NAME" << setw(10)<<"SCORES" <<endl;
	cout <<"=============" << setw(10) <<"=====" <<endl;
	
	for(int i=0; i<10; i++)
	{
		cout << left << setw(18) << name[i] << setw(10) << scores[i] <<endl;
	}
	cout << "\nHIGHEST SCORE" << setw(5) <<": "<<scores[getHighestScore(scores)]<< "(" <<name[getHighestScore(scores)] <<")" <<endl;
	cout << "LOWEST SCORE" << setw(6) <<": "<<scores[getLowestScore(scores)]<< "(" <<name[getLowestScore(scores)] <<")" <<endl;
	cout << "AVERAGE SCORE" << setw(5) <<": "<< averageScore(scores);
}

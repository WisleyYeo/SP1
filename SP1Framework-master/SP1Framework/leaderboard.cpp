
#include <string> 
#include <iostream> 
#include <fstream> 
#include "leaderboard.h"

using std::string;
using std::ifstream;
using std::ofstream;

using std::endl;



int LoadLB(string File, LeaderBoard* pLB)
{
	ifstream myFile(File);
	int i = 0;

	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile >> pLB[i].Name;
			myFile >> pLB[i].Score;
			i++;
		}
	}
	return i;
}

int PrintLB(string File, LeaderBoard* pLB)
{
	ofstream myFile(File);
	int  i = 0;

	if (myFile.is_open())
	{
		while (pLB->Name.length())
		{
			myFile << pLB->Name << " " << pLB->Score << endl;
			i++;
			pLB++;
		}
	}

	return i;
}
#include "Highscore.h"
#include <iostream>
#include <string>
#include <fstream>


using std::string;
using std::cout;
using std::endl;






void LoadHS(string File, Highscore *Player)
{
	int i = 0;
	std::ifstream Highscore(File);

	if (Highscore.is_open())
	{
		while (!Highscore.eof())
		{

			Highscore >> Player[i].Name;
			Highscore >> Player[i].Score;
			i++;
		}
	}
	Highscore.close();
}

void PrintHS(string File, Highscore *Player)
{
	int i = 0;
	int j = 1;

	cout << "---HIGHSCORES---" << endl;


	while (Player[i].Name.length() != 0)
	{
		cout << j << ". " << Player[i].Name << " " << Player[i].Score << endl;
		i++;
		j++;
	}




}

void WriteHS(string File, Highscore *Player)
{
	std::ofstream Highscore(File);
	int i = 0;



	if (Highscore.is_open())
	{
		while (Player->Name.length())
		{
			Highscore << Player->Name << " " << Player->Score << endl;
			i++;
			Player++;

		}
	}
	Highscore.close();
}


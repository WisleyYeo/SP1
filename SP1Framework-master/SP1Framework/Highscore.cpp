#include "Highscore.h"
#include "Framework\console.h"
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

void PrintHS(Highscore *Player)
{
	int i = 0;
	int j = 1;

	SetConsoleTitle(L"HIGHSCORES");

	cout << "---HIGHSCORES---" << endl;


	while (Player[i].Name.length() != 0)
	{
		cout << j << ". " << Player[i].Name << " " << Player[i].Score << endl;
		i++;
		j++;
	}

	cout << endl <<  "[F1]Return To Main Menu" << endl;
	cout << "[ESC]Exit Game" << endl;




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

void SortHS(Highscore *Player)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (Player[i].Score < Player[j].Score)
			{
				string TempName = Player[i].Name;
				int TempScore = Player[i].Score;
				Player[i].Name = Player[j].Name;
				Player[i].Score = Player[j].Score;
				Player[j].Name = TempName;
				Player[j].Score = TempScore;
			}
		}
	}
}


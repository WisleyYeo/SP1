#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <iostream>
#include <string>

using std::string;



struct Highscore
{
	string Name;
	int Score;
};


void LoadHS(string File, Highscore *Player);
void PrintHS(string File, Highscore *Player);
void WriteHS(string File, Highscore *Player);


#endif

#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <string>


using std::string;
//leaderboard

struct LeaderBoard
{
	string Name;
	int Score;
};

int LoadLB(string File, LeaderBoard*pLB);
int PrintLB(string File, LeaderBoard* pLB);



#endif
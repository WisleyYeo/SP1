#include "game.h"
#include "highscore.h"
#include "Framework\console.h"
#include "ball.h"
#include "catch.h"
#include "UI.h"
#include "time.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
extern vector<ball> ballwave;
bool fHandup = false;
extern COORD charLocation;
extern double elapsedTime;
extern int score;
double catchtimer;



void hand_down()
{
	if (elapsedTime > catchtimer)
	{
		fHandup = false;
	}
}

void check_ball_hand_position()
{
	for (size_t i = 0; i < ballwave.size(); ++i)
	{
		if (ballwave[i].inplay != 0)
		{

			if (ballwave[i].ballpos == charLocation.Y - 1 && ballwave[i].x == charLocation.X + 1)
			{		
				ballwave[i].inplay = 0;
				ballwave[i].ballpos = 1;	
				if (fHandup == true)
				{
					score += 3;
					// add score	
				}
				else
				{
					score -= 1;
				}	 //subtract score
			}	


		}
	}
}


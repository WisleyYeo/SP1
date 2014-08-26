#include "game.h"
#include "highscore.h"
#include "Framework\console.h"
#include "ball.h"
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
extern COORD charLocation1;

int score = 0;



void check_ball_hand_position()
{
	for (int i=0; i < ballwave.size();i++)
	{
		// check ball is active 
		if (ballwave[i].inplay)
		{

			if( ballwave[i].ballpos = charLocation1.Y && charLocation1.X  )
			{		
				ballwave[i].inplay = 0;
				ballwave[i].ballpos = 0;	
				if (fHandup)
				{
					// add score	
				}
				else {}	 //subtract lives
			}	

			
		}
	}
}


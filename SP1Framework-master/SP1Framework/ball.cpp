#include "ball.h"
#include "UI.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;


int balltimer = 0;

extern double elapsedTime;
extern COORD consoleSize;


vector<ball> ballwave;





void ballinit()
{
	gen_ball();
}

void gen_ball()
{
	for (size_t i = 0; i < 21; ++i)
	{
		ball BALL;
		ballwave.push_back(BALL);
		if (i == 0 || i == 7 || i == 14)
		{
			ballwave[i].x = 24;
		}
		else
		{
			ballwave[i].x = ballwave[i-1].x + 7;
		}
		ballwave[i].ballpos = 2;
		ballwave[i].inplay = 0;
	}
}

void ballfall()
{
	if (elapsedTime > balltimer)
	{
		ballwave[rand() %ballwave.size()].inplay += 1;
	}
	for (size_t i = 0; i < ballwave.size(); ++i)
	{
		if (ballwave[i].ballpos < consoleSize.Y && ballwave[i].inplay != 0)
		{
			if (elapsedTime > balltimer)
			{
				ballwave[i].ballpos += 1;
			}
			gotoXY(ballwave[i].x,ballwave[i].ballpos);
			colour(0x0F);
			cout << "(O)";
		}
		else if (ballwave[i].ballpos >= consoleSize.Y)
		{
			ballwave[i].inplay = 0;
			ballwave[i].ballpos = 1;
		}
	}
	if (elapsedTime > balltimer)
	{
		balltimer += 0.1;
	}
}
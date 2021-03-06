#include "ball.h"
#include "UI.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;


float balltimer = 1;
float pulsetimer = 1;
extern double elapsedTime;
extern COORD consoleSize;


vector<ball> ballwave;

void ballpulse(float x)
{
	if (elapsedTime > pulsetimer)
	{
		ballwave[rand() %ballwave.size()].inplay += 1;
		pulsetimer += x;
	}
}


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
		ballwave[i].ballpos = 1;
		ballwave[i].inplay = 0;
	}
}

void ballfall(float x,float y)
{
	ballpulse(x);
	for (size_t i = 0; i < ballwave.size(); ++i)
	{
		if (ballwave[i].ballpos < consoleSize.Y && ballwave[i].inplay != 0)
		{
			if (elapsedTime > balltimer)
			{
				ballwave[i].ballpos += 2;
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
		balltimer += y;
	}
	
}


void endfall()
{
		if (elapsedTime > 1000)
	{
		ballfall(0.1,0.1);
	}
	else if (elapsedTime > 100)
	{
		ballfall(2,0.5);
	}
	else if (elapsedTime > 80)
	{
		ballfall(2,0.6);
	}
	else if(elapsedTime > 60)
	{
		ballfall(2,0.7);
	}
	else if (elapsedTime > 40)
	{
		ballfall(2,0.8);
	}
	else if (elapsedTime > 20)
	{
		ballfall(2,0.9);
	}
	else
	{
		ballfall(2,1);
	}
}
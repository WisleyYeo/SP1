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


vector<meat> meatwave;



void ballfall()
{
	if (elapsedTime > balltimer)
	{
		//srand(time(NULL));
		meatwave[rand() %7].inplay += 1;
	}
	for (size_t i = 0; i < 14; ++i)
	{
		if (meatwave[i].ballpos < consoleSize.Y && meatwave[i].inplay != 0)
		{
			if (elapsedTime > balltimer)
			{
				meatwave[i].ballpos += 1;
			}
			gotoXY(meatwave[i].x,meatwave[i].ballpos);
			colour(0x0F);
			cout << "(O)";
		}
		else if (meatwave[i].ballpos >= consoleSize.Y)
		{
			meatwave[i].inplay = 0;
			meatwave[i].ballpos = 1;
		}
	}
	if (elapsedTime > balltimer)
	{
		balltimer += 0.8;
	}
}

void ballinit()
{

	

	meat meat1;
	meat meat2;
	meat meat3;
	meat meat4;
	meat meat5;
	meat meat6;
	meat meat7;
	meat meat8;
	meat meat9;
	meat meata;
	meat meatb;
	meat meatc;
	meat meatd;
	meat meate;
	meatwave.push_back(meat1);
	meatwave.push_back(meat2);
	meatwave.push_back(meat3);
	meatwave.push_back(meat4);
	meatwave.push_back(meat5);
	meatwave.push_back(meat6);
	meatwave.push_back(meat7);
	meatwave.push_back(meat8);
	meatwave.push_back(meat9);
	meatwave.push_back(meata);
	meatwave.push_back(meatb);
	meatwave.push_back(meatc);
	meatwave.push_back(meatd);
	meatwave.push_back(meate);
	for (size_t i = 0; i < 7; ++i)
	{
		meatwave[i].ballpos = 2;
		if (i == 0)
		{
			meatwave[i].x = i + 25;
		}
		else
		{
			meatwave[i].x = meatwave[i - 1].x + 7;
		}
		meatwave[i].inplay = 0;
	}
	for (size_t i = 7; i < 14; ++i)
	{
		meatwave[i].ballpos = 2;
		meatwave[i].x = i + 13;
		meatwave[i].inplay = 0;
	}
}

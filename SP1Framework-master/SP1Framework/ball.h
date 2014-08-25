#ifndef _BALL_H
#define _BALL_H

#include <vector>

using std::vector;

void ballfall();
void ballinit();


struct ball
{
	int x;
	int ballpos;
	bool inplay;
};




#endif
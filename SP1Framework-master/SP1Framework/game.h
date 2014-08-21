#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include <iostream>
#include <fstream>
#include <string>

using std::string;

extern StopWatch g_timer;
extern bool g_quitGame;
extern bool pausegame;
enum Keys
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
	K_1,
	K_2,
	K_SPACE,
	K_ENTER,
	K_BACKSPACE,
	K_HOME,
    K_ESCAPE,
    K_COUNT
};

void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory
void run();
void menu();
void mainLoop();
void background();
void pause();
void ballfall();




#endif // _GAME_H
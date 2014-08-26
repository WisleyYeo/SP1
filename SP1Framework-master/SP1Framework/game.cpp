// This is the main file for the game logic and function
//
//
#include "game.h"
#include "UI.h"
#include "ball.h"
#include "Highscore.h"
#include "Framework\console.h"
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



bool keyPressed[K_COUNT];
bool ingame = false;

double elapsedTime;
double deltaTime;
COORD charLocation;


COORD consoleSize;




GameState State = MAINMENU;





void init()
{
    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(2);
	
	
    SetConsoleTitle(L"CATCHBALLS");
	
    // Sets the console size, this is the biggest so far.
    setConsoleSize(79, 28);

    // Get console width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

    /* get the number of character cells in the current buffer */ 
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    consoleSize.X = csbi.srWindow.Right + 1;
    consoleSize.Y = csbi.srWindow.Bottom ;

    // set the character to be in the center of the screen.
    charLocation.X = consoleSize.X / 2 + 4;
    charLocation.Y = consoleSize.Y;

	

	ballinit();

	elapsedTime = 0.0;
	
}

void shutdown()
{
    // Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void getInput()
{    
    keyPressed[K_UP] = isKeyPressed(VK_UP);
    keyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
    keyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
    keyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
	keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	keyPressed[K_ENTER] = isKeyPressed(VK_RETURN);
	keyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
	keyPressed[K_BACKSPACE] = isKeyPressed(VK_BACK);
	keyPressed[K_HOME] = isKeyPressed(VK_HOME);
	keyPressed[K_1] = isKeyPressed(VK_F1);
	keyPressed[K_2] = isKeyPressed(VK_F2);
}




void update(double dt) //INGAME
{
	
	
	
	
	elapsedTime += dt;
	deltaTime = dt;

	

	switch (State)
	{
	
	case MAINMENU:
		updateMainMenu();
		break;
	case HIGHSCORE:
		updateHighscore();
		break;

	case INGAME:
		updateGame();
		break;

	case PAUSE:
		updatePause();
		break;

	case EXIT:
		updateExit();
		break;

	}
	
	
	// Updating the location of the character based on the key press

	if (keyPressed[K_LEFT] && charLocation.X > consoleSize.X/2 - 17)
	{
		
		
			charLocation.X-=7;
		
	}
	if (keyPressed[K_RIGHT] && charLocation.X < consoleSize.X - 16)
	{
		
			charLocation.X+=7;
		
	}
	if (keyPressed[K_ESCAPE])
	{
		g_quitGame = true;
	}
	
	
}

void updateHighscore()
{
	if (keyPressed[K_1])
	{
		State = MAINMENU;
	}
	if (keyPressed[K_ESCAPE])
	{
		State = EXIT;
	}
}

void updatePause()
{
	if (keyPressed[K_2]||keyPressed[K_ESCAPE])
	{
		State = EXIT;
	}
	if (keyPressed[K_1])
	{
		State = INGAME;
	}

}


void updateExit()
{
	return;
}



void updateGame()
{
	if (keyPressed[K_BACKSPACE])
	{
		State = PAUSE;
	}
	if (keyPressed[K_ESCAPE])
	{
		State = EXIT;
	}
}



void updateMainMenu()
{
	if (keyPressed[K_ENTER])
	{
		State = INGAME;
	}
	
	if (keyPressed[K_HOME])
	{
		State = HIGHSCORE;
	}

	if (keyPressed[K_ESCAPE])
	{
		State = EXIT;
	}
}


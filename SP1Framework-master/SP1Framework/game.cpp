// This is the main file for the game logic and function
//
//
#include "game.h"
#include "leaderboard.h"
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

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
bool ingame = false;

COORD charLocation;
COORD consoleSize;
int balltimer = 0;




struct meat
{
	int x;
	int ballpos;
	bool inplay;
};
vector<meat> meatwave;

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
    charLocation.X = consoleSize.X / 2;
    charLocation.Y = consoleSize.Y;

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
	ingame = true;
	
	elapsedTime += dt;
	deltaTime = dt;
	

	// Updating the location of the character based on the key press


	if (keyPressed[K_LEFT] && charLocation.X > 0)
	{
		charLocation.X--;
	}

	if (keyPressed[K_RIGHT] && charLocation.X < consoleSize.X - 1)
	{
		charLocation.X++;
	}
	
	if (keyPressed[K_BACKSPACE])
	{
		PAUSE;
		
	}
	// quits the game if player hits the escape key
	if (keyPressed[K_ESCAPE])
	{
		EXIT;
	}
	
}

//void updatePreGame()
//{
	

//}

void updateMainMenu()
{
	std::string output;
	std::ifstream Menu;
	Menu.open("menu.txt");

	SetConsoleTitle(L"MAIN MENU");



	while (!Menu.eof())
	{

		getline(Menu, output);
		std::cout << output << std::endl;

	}

	Menu.close();


	if (keyPressed[K_HOME])
	{
		//PREGAME;
		INGAME;
	}
	if (keyPressed[K_ESCAPE])
	{
		EXIT;
	}
	
	
	
}

void updatePause()
{
	ifstream PauseMenu;
	string Data;


	cls();

	PauseMenu.open("pausemenu.txt");
	while (!PauseMenu.eof())
	{
		getline(PauseMenu, Data);
		cout << Data << endl;
	}
	

	

	PauseMenu.close();

	if (keyPressed[K_2])
	{
		EXIT;
	}
	if (keyPressed[K_1])
	{
		return;
	}
}

void updateExit()
{
	cls();
	ifstream ragequit;
	string rage;
	ragequit.open("ragequit.txt");
	while (!ragequit.eof())
	{
		getline(ragequit, rage);
		cout << rage << endl;
	}
	g_quitGame = true;
}

void updateGame()
{
	
	
	GameState State = MAINMENU;
	
	switch (State)
	{
	case MAINMENU: updateMainMenu();
		break;
		
	//case PREGAME: updatePreGame();
	//	break; 
	
	case INGAME: update(g_timer.getElapsedTime());
		break;
		
	case PAUSE: updatePause();
		break;
		
	case EXIT: updateExit();
		break;
		

	}

}

void render()
{
    // clear previous screen
    colour(0x0F);
	
    cls();
	background();
	//ballfall();
	

    //render the game

    //render test screen code (not efficient at all)
    const WORD colors[] =   {
	                        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };
	
	

    // render time taken to calculate this frame
    gotoXY(70, 0);
    colour(0x1A);
    std::cout << 1.0 / deltaTime << "fps" << std::endl;
  
    gotoXY(0, 0);
    colour(0x59);
    std::cout << elapsedTime << "secs" << std::endl;

    // render character
    gotoXY(charLocation);
    colour(0x0C);
    cout << "  \\_/ ";
	gotoXY(charLocation.X, charLocation.Y - 1);
	cout << "I(*_*)I" << endl;
	gotoXY(charLocation.X, charLocation.Y - 2);
    cout << "   _" << endl;
}

void background()
{
	ifstream background;
	string data;

	background.open("background.txt");

	gotoXY(6, 0);

	while (!background.eof())
	{
		getline(background, data);
		cout << data << endl;
	}


	background.close();

}

void ballfall()
{
	if (elapsedTime > balltimer)
	{
		srand(time(NULL));
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
			cout << "O";
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




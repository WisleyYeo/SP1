// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD consoleSize;



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

void update(double dt)
{
	// get the delta time
	elapsedTime += dt;
	deltaTime = dt;

	// Updating the location of the character based on the key press


	if (keyPressed[K_LEFT] && charLocation.X > 0)
	{
		Beep(1440, 30);
		charLocation.X--;
	}
	
	if (keyPressed[K_RIGHT] && charLocation.X < consoleSize.X - 1)
	{
		Beep(1440, 30);
		charLocation.X++;
	}
	if (keyPressed[K_HOME])
	{
		run();
	}
	if (keyPressed[K_BACKSPACE])
	{
		pause();
	}
    // quits the game if player hits the escape key
	if (keyPressed[K_ESCAPE])
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
	if (keyPressed[K_1])
	{
		return;
	}

	if (keyPressed[K_2])
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
}

void render()
{
    // clear previous screen
    colour(0x0F);
	
    cls();
	
	

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
    std::cout << (char)3;

    
}

void menu()
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
	
}

void run()
{
	init();
	mainLoop();
	shutdown();
	
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

void pause()
{
	ifstream PauseMenu;
	string Data;
	int x = 0;

	cls();


	PauseMenu.open("pausemenu.txt");
	while (!PauseMenu.eof())
	{
		getline(PauseMenu, Data);
		cout << Data << endl;
	}
	system("PAUSE");

	getInput();

	
	

	PauseMenu.close();

	//getInput();
	


}



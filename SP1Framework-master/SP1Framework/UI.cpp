#include "UI.h"
#include "ball.h"
#include "game.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

#include "Framework\console.h"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;

extern double elapsedTime;
extern double deltaTime;
extern COORD charLocation;



string BackGround;
extern GameState State;



void renderExit()
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

void renderGame()
{
	colour(0x0F);
	cls();
	background();
	ballfall();



	//render the game


	//render test screen code (not efficient at all)
	const WORD colors[] = {
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
	cout << "/\\_/\\ ";
	gotoXY(charLocation.X, charLocation.Y - 1);
	cout << " (_)" << endl;
	gotoXY(charLocation.X, charLocation.Y - 2);
	cout << "  _" << endl;
	
}

void renderMainMenu()
{
	//Menu Title
	
		std::string output;
		std::ifstream Menu;
		Menu.open("menu.txt");
		SetConsoleTitle(L"MAIN MENU");
		cls();
		while (!Menu.eof())
		{

			getline(Menu, output);
			std::cout << output << std::endl;

		}
		Menu.close();

	
	
}

void renderPause()
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

	
}

void render()
{
	switch (State)
	{
	case MAINMENU:
		renderMainMenu();
		break;
	case INGAME:
		renderGame();
		break;
	case PAUSE:
		renderPause();
		break;
	case EXIT:
		renderExit();
		break;

	}

}

void background()
{
	ifstream background;


	background.open("background.txt");

	while (!background.eof())

	{
		getline(background, BackGround);
		cout << BackGround << endl;
	

	}
	background.close();

}
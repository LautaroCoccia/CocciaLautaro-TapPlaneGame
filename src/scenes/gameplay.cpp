#include "gameplay.h"

#include "raylib.h"

#include "objects/player.h"
#include "objects/obstacles.h"


player* player1;
obstacles* obs;

enum state 
{
	start,
	play,
	pause,
	lose
};
state gamestate = start;
gameplay::gameplay()
{
	obs = new obstacles();
	player1 = new player();
}
gameplay::~gameplay()
{
	
}
void gameplay::Start()
{
	player1->Start();
	obs->Start(0, DARKGREEN);
	
}
void gameplay::Update()
{
	switch (gamestate)
	{
	case start:
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			gamestate = play;
		}
		break;
	case play:
		obs->Update();
		player1->Input();
		player1->Update();
		if (IsKeyPressed(KEY_P))
		{
			gamestate = pause;
		}
		break;
	case pause:
		if (IsKeyPressed(KEY_P))
		{
			gamestate = play;
		}
		break;
	case lose:
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			gamestate = play;
		}
		break;
	default:
		break;
	}
	
}
void gameplay::Draw() 
{
	obs->Draw();
	player1->Draw();
	switch (gamestate)
	{
	case start:
		DrawText("Tap to start!", 310, 200, 20, BLACK);
		break;
	case play:
		break;
	case pause:
		DrawText("Pause!", GetScreenWidth() /2 , 200, 20, BLACK);
		break;
	case lose:
		DrawText("YOU LOSE!", GetScreenWidth() /2 , 200, 20, BLACK);
		break;
	default:
		break;
	}
}
void gameplay::Deinitialization()
{
	delete obs;
	delete player1;
}
void gameplay::SetGameStateLose()
{
	gamestate = lose;
}
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
	delete obs;
	delete player1;
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
		player1->Input();
		player1->Update();
		obs->Update();
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
		break;
	default:
		break;
	}
	
}
void gameplay::Draw() 
{
	player1->Draw();
	obs->Draw();
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

}
void gameplay::SetGameStateLose()
{
	gamestate = lose;
}
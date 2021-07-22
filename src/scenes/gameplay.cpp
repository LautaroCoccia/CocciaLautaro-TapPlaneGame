#include "gameplay.h"

#include "raylib.h"

#include "objects/game_manager.h"
#include "objects/player.h"
#include "objects/obstacles.h"


player* player1;
obstacles* obs;

Texture2D goToMenuButtonTexture;
Rectangle goToMenuButtonCollider;

Texture2D backgroundTexture;

Texture2D getReadyTexture;
Texture2D gameOverTexture;
enum buttonState
{
	up,
	mouseOver,
	down
};
buttonState actualButtonState;

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
	obs->Start();

	goToMenuButtonTexture = LoadTexture("Raw/UI/Mouse/buttonLarge.png");
	getReadyTexture = LoadTexture("Raw/UI/textGetReady.png");
	gameOverTexture = LoadTexture("Raw/UI/textGameOver.png");
	backgroundTexture = LoadTexture("Raw/UI/Backgrounds/background.png");

	goToMenuButtonCollider.width = static_cast<float>(goToMenuButtonTexture.width - 5);
	goToMenuButtonCollider.height = static_cast<float>(goToMenuButtonTexture.height);
	goToMenuButtonCollider.x = static_cast<float>(GetScreenWidth() / 2 - goToMenuButtonCollider.width / 2);
	goToMenuButtonCollider.y = 300;

	Restart();
}
void gameplay::Restart()
{
	player1->Restart();
	obs->Restart();
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
		if (CheckCollisionPointRec(GetMousePosition(), goToMenuButtonCollider))
		{
			if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
			{
				actualButtonState = down;
			}
			else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && actualButtonState == down)
			{
				enumScenes = gameplayScene;
				actualButtonState = up;
				this->Restart();
				gamestate = start;
				enumScenes = mainMenuScene;
			}
			else
			{
				actualButtonState = mouseOver;
			}
		}
		else
			actualButtonState = up;
	
		break;
	default:
		break;
	}
	
}
void gameplay::Draw() 
{
	DrawTexture(backgroundTexture, 0,0, WHITE);
	obs->Draw();
	player1->Draw();
	switch (gamestate)
	{
	case start:
		DrawTexture(getReadyTexture, static_cast<int>(GetScreenWidth() / 2 - getReadyTexture.width/2), static_cast<int>(GetScreenHeight() / 6),WHITE);
		DrawText("Tap to start!", 330, 300, 20, BLACK);
		break;
	case play:
		break;
	case pause:
		DrawText("Pause!", GetScreenWidth() /2 , 200, 20, BLACK);
		break;
	case lose:
		DrawTexture(gameOverTexture, static_cast<int>(GetScreenWidth() / 2 - gameOverTexture.width / 2), static_cast<int>(GetScreenHeight() / 6), WHITE);
		switch (actualButtonState)
		{
		case up:
			DrawTexture(goToMenuButtonTexture, 300, static_cast<int>(goToMenuButtonCollider.y), WHITE);
			break;
		case mouseOver:
			DrawTexture(goToMenuButtonTexture, 300, static_cast<int>(goToMenuButtonCollider.y), YELLOW);
			break;
		case down:
			DrawTexture(goToMenuButtonTexture, 300, static_cast<int>(goToMenuButtonCollider.y), BEIGE);
			break;
		default:
			break;
		}

		DrawText("MAIN MENU!", (GetScreenWidth() /2 -90) , static_cast<int>(goToMenuButtonCollider.y) +15, 30, BLACK);
		break;
	default:
		break;
	}
}
void gameplay::Deinitialization()
{
	UnloadTexture(backgroundTexture);
	UnloadTexture(gameOverTexture);
	UnloadTexture(getReadyTexture);
	UnloadTexture(goToMenuButtonTexture);
	obs->Deinitialization();
	player1->Deinitialization();
	delete obs;
	delete player1;
}
void gameplay::SetGameStateLose()
{
	gamestate = lose;
}

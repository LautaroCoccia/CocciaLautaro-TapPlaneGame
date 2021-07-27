#include "gameplay.h"

#include "raylib.h"

#include "objects/game_manager.h"
#include "objects/player.h"
#include "objects/obstacles.h"

using namespace TapGamePlane;

namespace TapGamePlane
{
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

	Music loopMusic;
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


		goToMenuButtonTexture = LoadTexture("Assets/UI/Buttons/buttonLarge.png");
		getReadyTexture = LoadTexture("Assets/UI/textGetReady.png");
		gameOverTexture = LoadTexture("Assets/UI/textGameOver.png");
		backgroundTexture = LoadTexture("Assets/UI/Background/background.png");

		loopMusic = LoadMusicStream("Assets/Audio/Music/MusicLoop.ogg");
		
		goToMenuButtonCollider.width = static_cast<float>(goToMenuButtonTexture.width);
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
		UpdateMusicStream(loopMusic);

		switch (gamestate)
		{
		case start:
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				PlayMusicStream(loopMusic);
				gamestate = play;
			}
			break;
		case play:
			obs->Update();
			player1->Input();
			player1->Update();
			if (IsKeyPressed(KEY_P))
			{
				PauseMusicStream(loopMusic);
				gamestate = pause;
			}
			break;
		case pause:
			if (IsKeyPressed(KEY_P))
			{
				ResumeMusicStream(loopMusic);
				gamestate = play;
			}
			if (CheckCollisionPointRec(GetMousePosition(), goToMenuButtonCollider))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					actualButtonState = down;
				}
				else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && actualButtonState == down)
				{
					StopMusicStream(loopMusic);
					enumScenes = gameplayScene;
					actualButtonState = up;
					Restart();
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
		case lose:
			StopMusicStream(loopMusic);
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
					Restart();
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
		DrawTexture(backgroundTexture, 0, 0, WHITE);
		obs->Draw();
		player1->Draw();
		DrawText("'P' to pause", 1, 0, 20, BLACK);

		switch (gamestate)
		{
		case start:
			DrawTexture(getReadyTexture, (GetScreenWidth() / 2 - getReadyTexture.width / 2), GetScreenHeight() / 6, WHITE);
			DrawText("click to start!", 330, 300, 20, BLACK);
			break;
		case play:
			DrawText(FormatText("%i", player1->GetScore()), GetScreenWidth() / 2 - 10, GetScreenHeight() / 4, 40, BLACK);
			break;
		case pause:
			DrawText("Pause!", GetScreenWidth() / 2, 200, 20, BLACK);
			switch (actualButtonState)
			{
			case up:
				DrawTexture(goToMenuButtonTexture, static_cast<int>(goToMenuButtonCollider.x), static_cast<int>(goToMenuButtonCollider.y), WHITE);
				break;
			case mouseOver:
				DrawTexture(goToMenuButtonTexture, static_cast<int>(goToMenuButtonCollider.x), static_cast<int>(goToMenuButtonCollider.y), YELLOW);
				break;
			case down:
				DrawTexture(goToMenuButtonTexture, static_cast<int>(goToMenuButtonCollider.x), static_cast<int>(goToMenuButtonCollider.y), BEIGE);
				break;
			default:
				break;
			}
			DrawText("MAIN MENU!", (GetScreenWidth() / 2 - 90), static_cast<int>(goToMenuButtonCollider.y) + 15, 30, BLACK);
			break;
		case lose:
			DrawText(FormatText("%i", player1->GetScore()), GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 20, 40, BLACK);
			DrawTexture(gameOverTexture, static_cast<int>(GetScreenWidth() / 2 - gameOverTexture.width / 2), static_cast<int>(GetScreenHeight() / 6), WHITE);
			switch (actualButtonState)
			{
			case up:
				DrawTexture(goToMenuButtonTexture, static_cast<int>(goToMenuButtonCollider.x), static_cast<int>(goToMenuButtonCollider.y), WHITE);
				break;
			case mouseOver:
				DrawTexture(goToMenuButtonTexture, static_cast<int>(goToMenuButtonCollider.x), static_cast<int>(goToMenuButtonCollider.y), YELLOW);
				break;
			case down:
				DrawTexture(goToMenuButtonTexture, static_cast<int>(goToMenuButtonCollider.x), static_cast<int>(goToMenuButtonCollider.y), BEIGE);
				break;
			default:
				break;
			}

			DrawText("MAIN MENU!", (GetScreenWidth() / 2 - 90), static_cast<int>(goToMenuButtonCollider.y) + 15, 30, BLACK);
			break;
		default:
			break;
		}
	}
	void gameplay::Deinitialization()
	{
		UnloadMusicStream(loopMusic);
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
}


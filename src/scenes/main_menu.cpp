#include "main_menu.h"

#include "raylib.h"

#include "objects/game_manager.h"

Texture2D background;

Texture2D playButtonTexture;
Texture2D quitButtonTexture;
Rectangle playButtonCollider;
Rectangle quitButtonCollider;
enum buttonState
{
	up,
	mouseOver,
	down
};
buttonState playButtonState;
buttonState quitButtonState;
main_menu::main_menu()
{
}
main_menu::~main_menu()
{
	
}
void main_menu::Start()
{
	background = LoadTexture("Raw/UI/Backgrounds/background.png");
	playButtonTexture = LoadTexture("Raw/UI/Mouse/buttonLarge.png");
	quitButtonTexture = LoadTexture("Raw/UI/Mouse/buttonSmall.png");
	Restart();

}
void main_menu::Restart()
{
	playButtonCollider.width = static_cast<float>(playButtonTexture.width - 5);
	playButtonCollider.height = static_cast<float>(playButtonTexture.height);
	playButtonCollider.x = static_cast<float>(GetScreenWidth() / 2 - playButtonCollider.width / 2);
	playButtonCollider.y = 200;
	playButtonState = up;

	quitButtonCollider.width = static_cast<float>(quitButtonTexture.width);
	quitButtonCollider.height = static_cast<float>(quitButtonTexture.height);
	quitButtonCollider.x = static_cast<float>(GetScreenWidth() / 2 - quitButtonCollider.width / 2);
	quitButtonCollider.y = 300;
	quitButtonState = up;
}

void main_menu::Update()
{
	if (CheckCollisionPointRec(GetMousePosition(), playButtonCollider))
	{
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			playButtonState = down;
		}
		else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && playButtonState == down)
		{
			enumScenes = gameplayScene;
			playButtonState = up;
		}
		else
		{
			playButtonState = mouseOver;
		}
	}
	else
		playButtonState = up;
	if (CheckCollisionPointRec(GetMousePosition(), quitButtonCollider))
	{
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			quitButtonState = down;
		}
		else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && quitButtonState == down)
		{
			quitButtonState = up;
			enumScenes = quitGame;
		}
		else
		{
			quitButtonState = mouseOver;
		}
	}
	else
		quitButtonState = up;

}
void main_menu::Draw()
{
	DrawTexture(background, 0, 0, LIGHTGRAY);
	switch (playButtonState)
	{
	case up:
		DrawTexture(playButtonTexture, 300 , 200, WHITE);
		break;
	case mouseOver:
		DrawTexture(playButtonTexture, 300 , 200, YELLOW);
		break;
	case down:
		DrawTexture(playButtonTexture, 300 , 200, BEIGE);
		break;
	default:
		break;
	}
	switch (quitButtonState)
	{
	case up:
		DrawTexture(quitButtonTexture, static_cast<int>(GetScreenWidth() / 2 - quitButtonTexture.width / 2), 300, WHITE);
		break;
	case mouseOver:
		DrawTexture(quitButtonTexture, static_cast<int>(GetScreenWidth() / 2 - quitButtonTexture.width / 2), 300, YELLOW);
		break;
	case down:
		DrawTexture(quitButtonTexture, static_cast<int>(GetScreenWidth()/2 -quitButtonTexture.width/2), 300, BEIGE);
		break;
	default:
		break;
	}

	DrawText("QUIT", static_cast<int>(GetScreenWidth() / 2)-45, 320, 40,BLACK);
	DrawText("PLAY", 350, 210, 40, BLACK);

}
void main_menu::Deinitialization()
{
	UnloadTexture(background);
	UnloadTexture(quitButtonTexture);
	UnloadTexture(playButtonTexture);
}
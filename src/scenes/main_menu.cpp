#include "main_menu.h"

#include "raylib.h"

#include "objects/game_manager.h"

Texture2D buttonTexture;
Rectangle buttonCollider;
enum buttonState
{
	up,
	mouseOver,
	down
};
buttonState state;
main_menu::main_menu()
{

}
main_menu::~main_menu()
{
	
}
void main_menu::Start()
{
	buttonTexture = LoadTexture("Raw/UI/Mouse/buttonLarge.png");
	buttonCollider.width = static_cast<float>(buttonTexture.width-5);
	buttonCollider.height = static_cast<float>(buttonTexture.height);
	buttonCollider.x = static_cast<float>(GetScreenWidth() / 2 - buttonCollider.width / 2);
	buttonCollider.y = 200;
	state = up;
}
void main_menu::Update()
{
	if (CheckCollisionPointRec(GetMousePosition(),buttonCollider))
	{
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			state = down;
		}
		else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && state == down)
		{
			enumScenes = gameplayScene;
			state = up;
		}
		else
		{
			state = mouseOver;
		}
	}
	else
		state = up;
}
void main_menu::Draw()
{
	switch (state)
	{
	case up:
		DrawTexture(buttonTexture, 300 , 200, WHITE);
		break;
	case mouseOver:
		DrawTexture(buttonTexture, 300 , 200, YELLOW);
		break;
	case down:
		DrawTexture(buttonTexture, 300 , 200, GREEN);
		break;
	default:
		break;
	}
	DrawText("PLAY", 350, 210, 40, BLACK);

}
void main_menu::Deinitialization()
{
	UnloadTexture(buttonTexture);
}
#include "player.h"

#include "raylib.h"

Vector2 position;

Rectangle playerVisual;

int score = 0;
int movementUp = 50;
int speed = 175;
Texture2D playerTexture;
int playerSize = 40;
void player::Start() 
{
	playerTexture = LoadTexture("Raw/UI/Player/planeRed2.png");
	playerTexture.height = playerTexture.height / 2;
	playerTexture.width = playerTexture.width / 2;
	playerVisual.height = static_cast<float>(playerSize);
	playerVisual.width = static_cast<float>(playerSize);
}
void player::Restart()
{

	position.x = static_cast<float>(GetScreenWidth() / 2 - playerVisual.width / 2);
	position.y = static_cast<float>(GetScreenHeight() / 2 - playerVisual.height / 2);

	playerVisual.x = position.x;
	playerVisual.y = position.y;
	score = 0;
}
void player::Input()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		playerVisual.y -= movementUp;
	}
}
void player::Update()
{
	if (playerVisual.y + playerSize < GetScreenHeight())
	{
		playerVisual.y  += speed * GetFrameTime() ;
	}
}
void player::Draw()
{
	DrawTexture(playerTexture, static_cast<int>(playerVisual.x), static_cast<int>(playerVisual.y), WHITE);
}
void player::UpdatePlayerScore()
{
	score++;
}
void player::Deinitialization()
{
	UnloadTexture(playerTexture);
}
int player::GetScore()
{
	return score;
}
Rectangle player::GetPlayerRectangle()
{
	return playerVisual;
}
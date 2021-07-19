#include "player.h"

#include "raylib.h"
Vector2 position;

Rectangle playerVisual;

int movementUp = 0;

player::player()
{
	
}
player::~player()
{

}
void player::Start() 
{
	playerVisual.height = 40;
	playerVisual.width = 40;

	position.x = static_cast<float>(GetScreenWidth() / 2 - playerVisual.width / 2);
	position.y = static_cast<float>(GetScreenHeight() / 4 - playerVisual.height / 2);

	playerVisual.x = position.x;
	playerVisual.y = position.y;
}
void player::Input()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		playerVisual.y -= 50;
	}
}
void player::Update()
{
	if (playerVisual.y + 40 < GetScreenHeight())
	{
		playerVisual.y  += 175 * GetFrameTime() ;
	}
}
void player::Draw()
{
	DrawRectangleRec(playerVisual, RED);
}
Rectangle player::GetPlayerRectangle()
{
	return playerVisual;
}
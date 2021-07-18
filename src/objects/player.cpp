#include "player.h"

#include "raylib.h"
Vector2 position;

Rectangle playerVisual;

int FloatToInt(float value);

player::player()
{
	
}
int movementUp = 0;
player::~player()
{

}
void player::Start() 
{
	playerVisual.x = position.x;
	playerVisual.y = position.y;

	playerVisual.height = 40;
	playerVisual.width = 40;

	position.x = static_cast<float>(GetScreenWidth() / 2);
	position.y = static_cast<float>(GetScreenHeight() / 4 - playerVisual.height / 2);
}
void player::Input()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		position.y -= 50;
	}
}
void player::Update()
{
	if (position.y + 40 < GetScreenHeight()) 
	{
		position.y  += 175 * GetFrameTime() ;
	}
}
void player::Draw()
{
	DrawRectangle(GetScreenWidth() / 2 - 20 , FloatToInt(position.y), FloatToInt(playerVisual.width), FloatToInt(playerVisual.height), RED);
}
int FloatToInt(float value)
{
	return static_cast<int>(value);
}
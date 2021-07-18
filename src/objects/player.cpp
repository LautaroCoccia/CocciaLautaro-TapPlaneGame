#include "player.h"

#include "raylib.h"
Vector2 position;

Rectangle playerVisual;
player::player()
{
	//position.x = static_cast<float>(GetScreenWidth() / 2);
	position.y = static_cast<float>(GetScreenHeight() / 2 - 20);
	playerVisual.x = position.x;
	playerVisual.y = position.y;
	playerVisual.height = 40;
	playerVisual.width = 40;
}
int movementUp = 0;
player::~player()
{

}
void player::Start() 
{

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
	if (position.y +40 < GetScreenHeight())
	{
		position.y  += 175 * GetFrameTime() ;
	}
}
void player::Draw()
{
	DrawRectangle(GetScreenWidth() / 2 - 20 , static_cast<int>(position.y), 40 , 40, RED);
}
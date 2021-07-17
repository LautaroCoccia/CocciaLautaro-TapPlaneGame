#include "player.h"

#include "raylib.h"
Vector2 position;

Rectangle rec;
player::player()
{
	//position.x = static_cast<float>(GetScreenWidth() / 2);
	//position.y = static_cast<float>(GetScreenHeight() / 2);
	rec.x = position.x;
	rec.y = position.y;
	rec.height = 40;
	rec.width = 40;
}
player::~player()
{

}
void player::Start() 
{

}
void player::Input()
{

}
void player::Update()
{

}
void player::Draw()
{
	DrawRectangle(GetScreenWidth() / 2 - 20, GetScreenHeight() / 2 -20, 40, 40, RED);
	DrawRectanglePro(rec, position, 0, RED);
}
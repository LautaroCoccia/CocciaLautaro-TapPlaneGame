#include "obstacles.h"

#include "raylib.h"
#include <iostream>
using namespace std;
Vector2 objUpPosition;
Vector2 objDownPosition;

Rectangle recUpvisual;
Rectangle recDownvisual;

int speed = 5;

float height = 100;
float width = 100;
obstacles::obstacles()
{
}
obstacles::~obstacles()
{

}
void obstacles::Start()
{
	objUpPosition.x = static_cast<float>(GetScreenWidth());
	objUpPosition.y = 0;

	objDownPosition.x = static_cast<float>(GetScreenWidth());
	objDownPosition.y = static_cast<float>(GetScreenHeight());
	
	recUpvisual.width = objUpPosition.x;
	recUpvisual.height = objUpPosition.y;
	recUpvisual.x = width;
	recUpvisual.y = height;

	recDownvisual.width = objDownPosition.x;
	recDownvisual.height = objDownPosition.y;
	recDownvisual.x = width;
	recDownvisual.y = height;

}
void obstacles::Update()
{
	if (objUpPosition.x > 0 && objDownPosition.x > 0)
	{
		objUpPosition.x -= speed;
		objDownPosition.x -= speed;
	}
	else
	{
		objDownPosition.x = static_cast<float>(GetScreenWidth());
		objUpPosition.x = static_cast<float>(GetScreenWidth());
	}
}
void obstacles::Draw()
{
	DrawRectangle(static_cast<int>(objUpPosition.x), static_cast<int>(objUpPosition.y), 
		static_cast<int>(width), static_cast<int>(height), RED);
	DrawRectangle(static_cast<int>(objDownPosition.x), static_cast<int>(objDownPosition.y - height),
		static_cast<int>(width), static_cast<int>(height) , BLUE);
}

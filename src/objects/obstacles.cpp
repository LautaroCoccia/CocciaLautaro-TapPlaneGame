#include "obstacles.h"

#include <iostream>
using namespace std;

const int maxObs = 3;
struct OBSTACLE
{
	Rectangle recUp;
	Rectangle recDown;
	int speed = 100;
	Color colorxd;
	
};
OBSTACLE obs[maxObs];
obstacles::obstacles()
{

}
obstacles::~obstacles()
{

}
void obstacles::Start(float xPosition, Color color)
{
	xPosition = 0;
	for (int i = 0; i < maxObs; i++)
	{
		obs[i].recUp.x = static_cast<float>(GetScreenWidth() + xPosition);
		obs[i].recUp.y = 0;
		obs[i].recUp.width = 45;
		obs[i].recUp.height = 120;

		obs[i].recDown.width = 45;
		obs[i].recDown.height = 120;
		obs[i].recDown.x = static_cast<float>(GetScreenWidth() + xPosition);
		obs[i].recDown.y = static_cast<float>(GetScreenHeight() - obs[i].recDown.height);
		obs[i].colorxd = color;
		xPosition += 300;
	}
	

}
void obstacles::Update()
{
	for (int i = 0; i < maxObs; i++)
	{
		if (obs[i].recUp.x + obs[i].recUp.width> 0 && obs[i].recDown.x + obs[i].recDown.width > 0)
		{

			obs[i].recUp.x -= obs[i].speed * GetFrameTime();
			obs[i].recDown.x -= obs[i].speed * GetFrameTime();
		}
		else
		{
			obs[i].recUp.x = static_cast<float>(GetScreenWidth());
			obs[i].recDown.x = static_cast<float>(GetScreenWidth());
		}
	}
}
void obstacles::Draw()
{
	for (int i = 0; i < maxObs; i++)
	{
		DrawRectangleRec(obs[i].recUp, obs[i].colorxd);
		DrawRectangleRec(obs[i].recDown, obs[i].colorxd);
	}
}

#include "obstacles.h"

#include <ctime>
#include <iostream>

#include "player.h"
using namespace std;

const int maxObs = 3;

const int minMaxPosYRange = 100;
player player1;
struct OBSTACLE
{
	Rectangle recUp;
	Rectangle recDown;
	int speed = 100;
	Color colorxd;
	
};
OBSTACLE obs[maxObs];

void CheckCollisionWithPlayer();

obstacles::obstacles()
{
	srand(static_cast<unsigned>( time(0))); 

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
		obs[i].recUp.height = 200;
		obs[i].recUp.width = 45;
		obs[i].recUp.y = 0 - obs[i].recUp.height/4;

		obs[i].recDown.width = 45;
		obs[i].recDown.height = 200;
		obs[i].recDown.x = static_cast<float>(GetScreenWidth() + xPosition);
		obs[i].recDown.y = static_cast<float>(GetScreenHeight() - obs[i].recDown.height/1.25);
		obs[i].colorxd = color;
		xPosition += 300;
	}
	

}
void obstacles::Update()
{
	CheckCollisionWithPlayer();
	for (int i = 0; i < maxObs; i++)
	{
		if (obs[i].recUp.x + obs[i].recUp.width> 0 && obs[i].recDown.x + obs[i].recDown.width > 0)
		{
			obs[i].recUp.x -= obs[i].speed * GetFrameTime();
			obs[i].recDown.x -= obs[i].speed * GetFrameTime();
		}
		else
		{
			int randomPosY = 50 - (rand() % 201);
			obs[i].recUp.x = static_cast<float>(GetScreenWidth());
			obs[i].recUp.y = static_cast<float>(randomPosY);
			obs[i].recDown.x = static_cast<float>(GetScreenWidth());
			obs[i].recDown.y = static_cast<float>(randomPosY + GetScreenHeight() - obs[i].recDown.height/3);
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
void CheckCollisionWithPlayer()
{
	for (int i = 0; i < maxObs; i++)
	{
		
		if (CheckCollisionRecs(player1.GetPlayerRectangle(), obs[i].recUp) ||
			CheckCollisionRecs(player1.GetPlayerRectangle(), obs[i].recDown))
		{
			cout << "YOU LOSE" << endl;
		}
	}
}

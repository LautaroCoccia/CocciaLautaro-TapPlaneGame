#include "obstacles.h"

#include <ctime>
#include <iostream>

#include "scenes/gameplay.h"
#include "player.h"
using namespace std;

const int maxObs = 3;

const int minMaxPosYRange = 100;

Texture2D obstacleUpTexture;
Texture2D obstacleDownTexture;

player player1;
struct OBSTACLE
{
	Rectangle recMid;
	Rectangle recUp;
	Rectangle recDown;
	int speed = 150;
	Color colorxd;
	enum collision
	{
		noColl,
		colliding,
		scorerer
	};
	collision collisionState;
};

OBSTACLE obs[maxObs];

void CheckCollisionWithPlayer();

obstacles::obstacles()
{
	srand(static_cast<unsigned>(time(0))); 
}
obstacles::~obstacles()
{
	UnloadTexture(obstacleUpTexture);
	UnloadTexture(obstacleDownTexture);
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

		obs[i].recMid.width = 60;
		obs[i].recMid.height = obs[i].recDown.y - obs[i].recUp.height + (obs[i].recUp.y * -1);
		obs[i].recMid.x = static_cast<float>(GetScreenWidth() + xPosition);
		obs[i].recMid.y =  obs[i].recUp.height +obs[i].recUp.y;

		obs[i].colorxd = color;
		obs[i].collisionState = obs[i].noColl;
		xPosition += 300;
		
		
	}
	obstacleUpTexture = LoadTexture("Raw/UI/Obstacles/rockGrassDown.png");
	obstacleUpTexture.height = static_cast<int>(obstacleUpTexture.height / 1.20f);
	obstacleDownTexture = LoadTexture("Raw/UI/Obstacles/rockGrass.png");
	obstacleDownTexture.height = static_cast<int>(obstacleDownTexture.height / 1.20f);
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
			obs[i].recMid.x -= obs[i].speed *GetFrameTime();
		}
		else
		{
			int randomPosY = 50 - (rand() % 150);
			obs[i].recUp.x = static_cast<float>(GetScreenWidth());
			obs[i].recUp.y = static_cast<float>(randomPosY);

			obs[i].recMid.y = obs[i].recUp.height + obs[i].recUp.y;
			obs[i].recMid.x = static_cast<float>(GetScreenWidth());

			obs[i].recDown.x = static_cast<float>(GetScreenWidth());
			obs[i].recDown.y = static_cast<float>(obs[i].recMid.y + obs[i].recMid.height);
		}
	}
}
void obstacles::Draw()
{
	for (int i = 0; i < maxObs; i++)
	{
		DrawTexture(obstacleUpTexture, static_cast<int>(obs[i].recUp.x - obstacleUpTexture.width /2.5 ), static_cast<int>(obs[i].recUp.y),WHITE);
		DrawTexture(obstacleDownTexture, static_cast<int>(obs[i].recDown.x - obstacleUpTexture.width /2.5 ), static_cast<int>(obs[i].recDown.y),WHITE);
	}
}
void CheckCollisionWithPlayer()
{
	for (int i = 0; i < maxObs; i++)
	{
		if (CheckCollisionRecs(player1.GetPlayerRectangle(), obs[i].recUp) ||
			CheckCollisionRecs(player1.GetPlayerRectangle(), obs[i].recDown))
		{
			gameplay game;
			game.SetGameStateLose();
		}
		else if (CheckCollisionRecs(player1.GetPlayerRectangle(), obs[i].recMid))
		{
			switch (obs[i].collisionState)
			{
			case obs[i].noColl:
				obs[i].collisionState = obs[i].colliding;
				break;
			default:
				break;
			}
		}
		else if (!(CheckCollisionRecs(player1.GetPlayerRectangle(), obs[i].recMid)) )
		{
			switch (obs[i].collisionState)
			{
			case obs[i].colliding:
				obs[i].collisionState = obs[i].scorerer; 
				break;
			case obs[i].scorerer:
				player1.UpdatePlayerScore();
				obs[i].collisionState = obs[i].noColl;
				break;
			default:
				break;
			}
			
		}
	}
}

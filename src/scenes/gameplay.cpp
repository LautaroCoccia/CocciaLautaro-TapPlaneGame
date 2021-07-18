#include "gameplay.h"

#include "raylib.h"

#include "objects/player.h"
#include "objects/obstacles.h"

player* player1;
obstacles* obs;

gameplay::gameplay()
{
	player1 = new player();
	obs = new obstacles();
}
gameplay::~gameplay()
{
	delete obs;
	delete player1;
}
void gameplay::Start()
{
	player1->Start();
	obs->Start();
}
void gameplay::Update()
{
	player1->Input();
	player1->Update();
	obs->Update();
}
void gameplay::Draw() 
{
	DrawText("This is game scene!", 310, 200, 20, BLACK);
	player1->Draw();
	obs->Draw();
}
void gameplay::Deinitialization()
{

}
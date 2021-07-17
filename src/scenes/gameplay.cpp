#include "gameplay.h"

#include "raylib.h"

#include "objects/player.h"

player* player1;
gameplay::gameplay()
{
	player1 = new player();
}
gameplay::~gameplay()
{
	delete player1;
}
void gameplay::Start()
{
	player1->Start();
}
void gameplay::Update()
{
	player1->Input();
	player1->Update();
}
void gameplay::Draw() 
{
	DrawText("This is game scene!", 310, 200, 20, BLACK);
	player1->Draw();

}
void gameplay::Deinitialization()
{

}
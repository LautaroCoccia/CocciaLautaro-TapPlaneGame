#include "main_menu.h"

#include "raylib.h"

Texture2D buttonTexture;
main_menu::main_menu()
{

}
main_menu::~main_menu()
{
	
}
void main_menu::Start()
{
	buttonTexture = LoadTexture("Raw/UI/Mouse/buttonLarge.png");

}
void main_menu::Update()
{
	
}
void main_menu::Draw()
{
	DrawText("This is main menu!", 310, 200, 20, BLACK);
	
	DrawTexture(buttonTexture, 300 , 160 - buttonTexture.height / 2, WHITE);
	DrawText("PLAY", 375, 150, 20, BLACK);

}
void main_menu::Deinitialization()
{

}
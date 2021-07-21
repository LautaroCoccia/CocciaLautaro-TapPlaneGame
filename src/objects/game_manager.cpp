#include "game_manager.h"

#include "raylib.h"

#include "scenes/main_menu.h"
#include "scenes/gameplay.h"

#include <iostream>

using namespace std;
const int screenWidth = 800;
const int screenHeight = 450;

main_menu* mainMenu;
gameplay* game;
void InitGame();
void Update();
void Draw();
void Deinitialization();
Vector2 GetMousePos();
bool IsMouseOnScreen();

Texture2D mouseImage;

scenes enumScenes;

game_manager::game_manager()
{
	mainMenu = new main_menu();
	game = new gameplay();
}
game_manager::~game_manager()
{
	delete game;
}
void game_manager::StartGame()
{
	enumScenes = mainMenuScene;
	InitGame();
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		Update();
		Draw();
	}
	Deinitialization();
}
void game_manager::SetActiveScene(scenes newActivescene)
{
	enumScenes = newActivescene;
	cout << "Escena: " << enumScenes << endl;
}
void InitGame()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(screenWidth, screenHeight, "Coccia Lautaro - Tap plane game");
	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	mouseImage = LoadTexture("Raw/UI/Mouse/tap.png");

	mainMenu->Start();
	game->Start();

}
void Update()
{
	if (IsMouseOnScreen())
		HideCursor();
	else
		ShowCursor();
	switch (enumScenes)
	{
	case mainMenuScene:

			mainMenu->Update();
		break;
	case gameplayScene:
			game->Update();
		break;
	default:
		break;
	}
	// Update
	//----------------------------------------------------------------------------------
	// TODO: Update your variables here
	//----------------------------------------------------------------------------------
}
void Draw()
{
	// Draw
	//----------------------------------------------------------------------------------
	BeginDrawing();
	switch (enumScenes)
	{
	case mainMenuScene:
		mainMenu->Draw();
		break;
	case gameplayScene:
		game->Draw();
		break;
	default:
		break;
	}
	DrawTexture(mouseImage, static_cast<int>(GetMousePos().x), 
		static_cast<int>(GetMousePos().y), WHITE);

	DrawLine(0, GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight() / 2, GREEN);
	DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), GREEN);

	ClearBackground(RAYWHITE);

	EndDrawing();
	//----------------------------------------------------------------------------------
}
void Deinitialization()
{
	game->Deinitialization();
	if (mainMenu != NULL)
	{
		mainMenu->Deinitialization();
		delete mainMenu;
	}
	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
}

Vector2 GetMousePos()
{
	Vector2 mousePosVec = { GetMousePosition().x - mouseImage.width / 2,
		GetMousePosition().y - mouseImage.height / 2 };
	return mousePosVec;
}

bool IsMouseOnScreen()
{
	return ((GetMousePosition().x > 0 && GetMousePosition().x < GetScreenWidth()) &&
		GetMousePosition().y > 0 && GetMousePosition().y < GetScreenHeight());
		
}


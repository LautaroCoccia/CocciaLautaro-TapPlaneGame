#include "game_manager.h"

#include "raylib.h"


const int screenWidth = 800;
const int screenHeight = 450;

void InitGame();
void Update();
void Draw();
void Deinitialization();

game_manager::game_manager()
{

}
game_manager::~game_manager()
{

}
void game_manager::StartGame()
{
	InitGame();
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		Update();
		Draw();
	}
	Deinitialization();
}
void InitGame()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(screenWidth, screenHeight, "Coccia Lautaro - Tap plane game");
	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
}
void Update()
{
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

	ClearBackground(RAYWHITE);

	DrawText("Congrats! You created your first window!", 190, 200, 20, BLACK);

	EndDrawing();
	//----------------------------------------------------------------------------------
}
void Deinitialization()
{
	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
}


#include "game_manager.h"

#include "raylib.h"

#include "scenes/main_menu.h"
#include "scenes/gameplay.h"

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
game_manager::game_manager()
{
	mainMenu = new main_menu();
	game = new gameplay();
}
game_manager::~game_manager()
{
	delete game;
	delete mainMenu;
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
	mouseImage = LoadTexture("Raw/UI/Mouse/tap.png");

	//mainMenu->Start();
	game->Start();

}
void Update()
{
	if (IsMouseOnScreen())
		DisableCursor();
	else
		EnableCursor();
	//mainMenu->Update();
	game->Update();
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
	
	//mainMenu->Draw();
	game->Draw();
	DrawTexture(mouseImage, static_cast<int>(GetMousePos().x), 
		static_cast<int>(GetMousePos().y), WHITE);

	DrawLine(0, GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight() / 2, GREEN);
	DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), GREEN);

	ClearBackground(RAYWHITE);

	/*DrawText("Congrats! You created your first window!", 190, 200, 20, BLACK);*/

	EndDrawing();
	//----------------------------------------------------------------------------------
}
void Deinitialization()
{
	//mainMenu->Deinitialization();
	game->Deinitialization();
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


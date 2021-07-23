#include "game_manager.h"

#include "raylib.h"

#include "scenes/main_menu.h"
#include "scenes/gameplay.h"

using namespace TapGamePlane;

namespace TapGamePlane
{

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
	
	Sound mouseClickSound;
	Sound mouseReleaseSound;
	enum mouseFrame
	{
		idle,
		click
	};
	mouseFrame actualMouseFrame;
	
	scenes enumScenes;
	
	Texture2D mouseTexture;
	Rectangle mouseFrameRec;
	Vector2 mouseTexturePosition;
	
	game_manager::game_manager()
	{
		mainMenu = new main_menu();
		game = new gameplay();
	}
	game_manager::~game_manager()
	{
	
	}
	void game_manager::StartGame()
	{
		enumScenes = mainMenuScene;
		actualMouseFrame = idle;
		InitGame();
		
		while ( (enumScenes !=quitGame && !WindowShouldClose()))    // Detect window close button or ESC key
		{
			Update();
			Draw();
		}
		Deinitialization();
	}
	void game_manager::SetActiveScene(scenes newActivescene)
	{
		enumScenes = newActivescene;
	}
	void InitGame()
	{
		// Initialization
		//--------------------------------------------------------------------------------------
		InitWindow(screenWidth, screenHeight, "Coccia Lautaro - Tap plane game");
		SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	
		InitAudioDevice();

		mouseTexture = LoadTexture("Assets/UI/Mouse/MouseTap.png");
		mouseClickSound = LoadSound("Assets/Audio/ClickSounds/mouseclick1.ogg");
		mouseReleaseSound = LoadSound("Assets/Audio/ClickSounds/mouserelease1.ogg");

		mouseFrameRec = { 0,0,static_cast<float>(mouseTexture.width / 2), static_cast<float>(mouseTexture.height) };
		mainMenu->Start();
		game->Start();
	}
	void Update()
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		mouseTexturePosition = { GetMousePos().x + mouseTexture.width / 4,GetMousePos().y + mouseTexture.height / 4 };
	
		if ( IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			PlaySound(mouseClickSound);
			actualMouseFrame = idle;
		}
		else if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			PlaySound(mouseReleaseSound);
			actualMouseFrame = click;

		}
		
		switch (actualMouseFrame)
		{
		case idle:
			mouseFrameRec.x = static_cast<float>(0 * mouseTexture.width / 2 );
			break;
		case click:
			mouseFrameRec.x = static_cast<float>(1 * mouseTexture.width / 2 );
			break;
		default:
			break;
		}
	
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
		DrawTextureRec(mouseTexture, mouseFrameRec, mouseTexturePosition, WHITE);
	
		DrawText("v0.13", 1, static_cast<int>(GetScreenHeight() - 20), 20, BLACK);
		DrawText("Tappy Plane assets by Kenney", static_cast<int>(GetScreenWidth()/3.5), static_cast<int>(GetScreenHeight() - 25), 20, BLACK);
	
		ClearBackground(RAYWHITE);
	
		EndDrawing();
		//----------------------------------------------------------------------------------
	}
	void Deinitialization()
	{
		if (game != NULL)
		{
			game->Deinitialization();
			delete game;
		}
		if (mainMenu != NULL)
		{
			mainMenu->Deinitialization();
			delete mainMenu;
		}
		UnloadSound(mouseReleaseSound);
		UnloadSound(mouseClickSound);
		UnloadTexture(mouseTexture);

		CloseAudioDevice();
		// De-Initialization
		//--------------------------------------------------------------------------------------
		CloseWindow();        // Close window and OpenGL context
		//--------------------------------------------------------------------------------------
	}
	
	Vector2 GetMousePos()
	{
		Vector2 mousePosVec = { GetMousePosition().x - mouseTexture.width / 2,
			GetMousePosition().y - mouseTexture.height / 2 };
		return mousePosVec;
	}
	
	bool IsMouseOnScreen()
	{
		return ((GetMousePosition().x > 0 && GetMousePosition().x < GetScreenWidth()) &&
			GetMousePosition().y > 0 && GetMousePosition().y < GetScreenHeight());
			
	
}
}


#include "game_manager.h"

#include "raylib.h"

namespace TapPlaneGame
{
	namespace GameManager
	{
		const int screenWidth = 800;
		const int screenHeight = 450;

		void UpdateGame();
		void StartGame()
		{
			// Initialization
			//--------------------------------------------------------------------------------------
			InitWindow(screenWidth, screenHeight, "CocciaLautaro - TapPlaneGame");
			SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

			// Main game loop
			UpdateGame();
		}
		
		//--------------------------------------------------------------------------------------
		// Main game loop
		void UpdateGame()
		{
			while (!WindowShouldClose())    // Detect window close button or ESC key
			{
				// Update
				//----------------------------------------------------------------------------------
				// TODO: Update your variables here
				//----------------------------------------------------------------------------------

				// Draw
				//----------------------------------------------------------------------------------
				BeginDrawing();

				ClearBackground(RAYWHITE);

				DrawText("Congrats! This isn't broken... yet!", 190, 200, 20, BLACK);

				EndDrawing();
				//----------------------------------------------------------------------------------
			}
			// De-Initialization
			//--------------------------------------------------------------------------------------
			CloseWindow();        // Close window and OpenGL context
			//--------------------------------------------------------------------------------------
		}
	}
}

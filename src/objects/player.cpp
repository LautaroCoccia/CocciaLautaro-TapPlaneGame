#include "player.h"

#include "raylib.h"

using namespace TapGamePlane;

namespace TapGamePlane
{
	Vector2 position;

	Rectangle playerVisual;

	int score = 0;
	int movementUp = 75;
	int speed = 175;
	int playerSize = 40;

	Texture2D playerTexture;

	Rectangle frameRec;
	int framesCounter = 0;
	int currentFrame = 0;
	int framesSpeed = 8;
	void player::Start()
	{
		playerTexture = LoadTexture("Assets/UI/Plane/Plane.png");
		playerTexture.height = playerTexture.height / 2;
		playerTexture.width = playerTexture.width / 2;

		playerVisual.height = static_cast<float>(playerSize);
		playerVisual.width = static_cast<float>(playerSize);

		frameRec = { 0,0, static_cast<float>(playerTexture.width / 3), static_cast<float>(playerTexture.height) };
	}
	void player::Restart()
	{
		position.x = static_cast<float>(GetScreenWidth() / 2 - playerVisual.width / 2);
		position.y = static_cast<float>(GetScreenHeight() / 2 - playerVisual.height / 2);

		playerVisual.x = position.x;
		playerVisual.y = position.y;
		score = 0;
	}
	void player::Input()
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			playerVisual.y -= movementUp;
		}
	}
	void player::Update()
	{
		framesCounter++;
		if (framesCounter >= (60 / framesSpeed))
		{
			framesCounter = 0;
			currentFrame++;
			if (currentFrame > 3) currentFrame = 0;
			frameRec.x = static_cast<float>(currentFrame * playerTexture.width / 3);
		}

		if (playerVisual.y + playerSize < GetScreenHeight())
		{
			playerVisual.y += speed * GetFrameTime();
		}
		position.x = playerVisual.x;
		position.y = playerVisual.y;
	}
	void player::Draw()
	{
		DrawTextureRec(playerTexture, frameRec, position, WHITE);
	}
	void player::UpdatePlayerScore()
	{
		score++;
	}
	void player::Deinitialization()
	{
		UnloadTexture(playerTexture);
	}
	int player::GetScore()
	{
		return score;
	}
	Rectangle player::GetPlayerRectangle()
	{
		return playerVisual;
	}
}

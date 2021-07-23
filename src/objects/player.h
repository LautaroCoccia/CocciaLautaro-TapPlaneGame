#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
namespace TapGamePlane
{
	class player
	{
	public:
		void Start();
		void Restart();
		void Input();
		void Update();
		void Draw();
		void UpdatePlayerScore();
		void Deinitialization();
		int GetScore();
		Rectangle GetPlayerRectangle();
	};
}
#endif // PLAYER_H




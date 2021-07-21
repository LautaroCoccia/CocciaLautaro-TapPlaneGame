#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
class player
{
public:
	void Start();
	void Input();
	void Update();
	void Draw();
	void UpdatePlayerScore();
	void Deinizialization();
	Rectangle GetPlayerRectangle();
};
#endif // PLAYER_H




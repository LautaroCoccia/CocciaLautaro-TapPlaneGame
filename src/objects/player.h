#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
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
	Rectangle GetPlayerRectangle();
};
#endif // PLAYER_H




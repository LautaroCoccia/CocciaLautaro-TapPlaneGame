#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
class player
{
public:
	player();
	~player();
	void Start();
	void Input();
	void Update();
	void Draw();
	Rectangle GetPlayerRectangle();
};
#endif // PLAYER_H




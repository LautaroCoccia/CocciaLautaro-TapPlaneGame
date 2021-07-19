#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "raylib.h"
class obstacles
{
public:
	
	obstacles();
	~obstacles();
	void Start(float xPosition, Color color);
	void Update();
	void Draw();
};
#endif


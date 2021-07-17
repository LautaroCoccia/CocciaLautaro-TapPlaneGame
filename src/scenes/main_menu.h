#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include "scene.h"
class main_menu : scene  
{
public:
	main_menu();
	~main_menu();
	void Start();
	void Update();
	void Draw();
	void Deinitialization();
};
#endif // !MAIN_MENU_H

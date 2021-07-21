#include "objects/game_manager.h"

int main(void)
{
	game_manager* GM = new game_manager();

	GM->StartGame();

	delete GM;
	
	return 0;
}
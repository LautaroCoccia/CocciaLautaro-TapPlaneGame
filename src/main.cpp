#include "objects/game_manager.h"

using namespace TapGamePlane;

int main()
{
	game_manager* GM = new game_manager();
	GM->StartGame();
	delete GM;
	return 0;
}
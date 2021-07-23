#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "raylib.h"


namespace TapGamePlane
{
	enum scenes
	{
		mainMenuScene,
		gameplayScene,
		quitGame
	};
	extern scenes enumScenes;

	class game_manager {

	public:
		game_manager();
		~game_manager();
		void StartGame();
		void SetActiveScene(scenes newActivescene);
	};
}

#endif
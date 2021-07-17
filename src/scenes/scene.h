#ifndef SCENE_H
#define SCENE_H

class scene
{
public: 
	enum scenes
	{
		mainMenuScene,
		gameplayScene,
		creditsScene,
		quitScene
	};
	int GetActiveScene();
	void SetActiveScene(int newActiveScene);
};
#endif // !SCENE_H
#include "scene.h"

int activeScene;

int scene::GetActiveScene()
{
	return activeScene;
}
void scene::SetActiveScene(int newActiveScene)
{
	activeScene = newActiveScene;
}
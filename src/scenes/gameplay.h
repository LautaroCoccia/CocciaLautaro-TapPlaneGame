#ifndef GAMEPLAY_H
#define GAMEPLAY_H

enum state
{
	start,
	play,
	pause,
	lose
};
extern state gamestate;
class gameplay
{
public:
	gameplay();
	~gameplay();
	void Start();
	void Update();
	void Draw();
	void Deinitialization();
	void SetGameStateLose();
};

#endif // !GAMEPLAY_H
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

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
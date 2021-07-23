#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace TapGamePlane
{
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
		void Restart();
		void Update();
		void Draw();
		void Deinitialization();
		void SetGameStateLose();
	};

#endif // !GAMEPLAY_H
}
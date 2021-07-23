#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "raylib.h"

namespace TapGamePlane
{
	class obstacles
	{
	public:
		obstacles();
		~obstacles();
		void Start();
		void Restart();
		void Update();
		void Draw();
		void Deinitialization();
	
	};
}
#endif


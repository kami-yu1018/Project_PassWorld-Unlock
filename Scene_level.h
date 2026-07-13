#pragma once
#include "Scene_bass.h"

class Scene_level :public Scene_bass
{
public:

	Scene_level()
	{ 
	}
	void Init();
	void Update();
	void Render();
	void Exit();
};
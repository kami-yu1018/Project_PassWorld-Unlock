#pragma once
#include "Scene_bass.h"

class Scene_play:public Scene_bass
{
public:
	Scene_play()
	{
	}

	void Init();
	void Update();
	void Render();
	void Exit();
};
#pragma once
#include "Scene_bass.h"

class Scene_setting :public Scene_bass
{
public:
	Scene_setting()
	{
	}
	void Init();
	void Update();
	void Render();
	void Exit();
};
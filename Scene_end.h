#pragma once
#include "Scene_bass.h"

class Scene_end :public Scene_bass
{
public:
	Scene_end()
	{
	}
	void Init();
	void Update();
	void Render(int end);
	void Exit();
};
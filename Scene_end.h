#pragma once
#include "Scene_bass.h"

class Scene_end :public Scene_bass
{
	int end_image[2];

public:
	Scene_end()
	{
	}
	void Init();
	void Update();
	void Render(int end);
	void Exit();
};
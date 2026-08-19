#pragma once
#include"Scene_bass.h"

class Scene_title :public Scene_bass
{
	int title_image;

public:
	Scene_title()
	{
	}
	void Init();
	void Update();
	void Render();
	void Exit();
};
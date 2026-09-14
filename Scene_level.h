#pragma once
#include "Scene_bass.h"

class Scene_level :public Scene_bass
{
	int background_image = 0;

	int level_image[3] = { 0,0,0 };
public:

	//	難易度（０：easy　１：nomal　２：hard）
	int lv = 0;

	Scene_level()
	{ 
	}
	void Init();
	void Update();
	void Render();
	void Exit();
};
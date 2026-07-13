#pragma once
#include "DxLib.h"
#include "main.h"

class Scene_bass
{
public:
	int next = 0;

	Scene_bass()
	{
	}

	void Init();
	void Update();
	void Render();
	void Exit();
};
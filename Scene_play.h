#pragma once
#include "Scene_bass.h"

class Scene_play:public Scene_bass
{
public:
	int end = 0;

	Scene_play()
	{
	}

	//	引数に難易度とプレイヤーのID
	void Init(int level,int p_1,int p_2,int p_3,int p_4);
	void Update();
	void Render();
	void Exit();
};
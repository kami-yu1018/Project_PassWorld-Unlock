#pragma once
#include "Scene_bass.h"
#include"Factory.h"
#include"Player.h"
#include"Enemy.h"

class Scene_play:public Scene_bass
{
	Enemy* enemy[3] = {};
	bool e_alive[3] = { 0,0,0 };
	Player* player[4] = {};
	bool p_alive[4] = {1,1,1,1};
public:

	Scene_play()
	{
	}

	//	引数に難易度とプレイヤーのID
	void Init(int level,int p_1,int p_2,int p_3,int p_4);
	void Update();
	void Render();
	void Exit();
};
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

	struct TurnActor
	{
		bool isEnemy;
		int index;
	};

	static const int player_count = 4;
	static const int enemy_count = 3;
	static const int actor_count = player_count + enemy_count;

	TurnActor turnOrder[actor_count];
	int TurnIndex = 0;
	int enemy_num = 0;

public:

	Scene_play()
	{
	}

	//	引数に難易度とプレイヤーのID
	void Init(int level,int p_1,int p_2,int p_3,int p_4);
	void Update();
	void Render();
	void Exit();

	void CreateTurn(int enemy_num);

	void NextTurn(int enemy_num);
};
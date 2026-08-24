#pragma once
#include "Scene_bass.h"
#include"Factory.h"
#include"Player.h"
#include"Enemy.h"
#include"Scene_setting.h"

class Scene_play:public Scene_bass
{
	int background = 0;

	//	敵
	Enemy* enemy[3] = {};
	bool e_alive[3] = { 0,0,0 };
	//	味方
	Player* player[4] = {};
	bool p_alive[4] = {1,1,1,1};

	//	現在のターンが敵かどうかを判断
	bool currentIsEnemy = false;

	//	敵味方の順番を決める用の構造体
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

	Scene_setting set_obj;

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
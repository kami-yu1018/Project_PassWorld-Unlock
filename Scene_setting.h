#pragma once
#include "Scene_bass.h"

enum
{
	BLANC,
	KENSI,
	MADOUSI,
	SOURYO,
	TOUZOKU,
	ZYUKISI,
	BUSHI,
	GINYUSIZIN
};

class Scene_setting :public Scene_bass
{
	int background_image = 0;
	int player_image[8] = { 0,0,0,0,0,0,0,0 };

public:
	//	スタメンのIDを入れる変数（4枠）
	int mem_ID[4];
	//	現在選択している枠
	int num = 0;
	//	現在選択しているキャラクター
	int chara_num = 1;
	
	bool charachenge_switch = 0;

	Scene_setting()
	{
	}
	void Init();
	void Update();
	void Render();
	void Exit();
};
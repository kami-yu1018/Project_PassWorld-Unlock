#pragma once
#include "Scene_bass.h"



class Scene_setting :public Scene_bass
{
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

	int background_image = 0;
	
public:
	int player_image[8] = { 0,0,0,0,0,0,0,0 };


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
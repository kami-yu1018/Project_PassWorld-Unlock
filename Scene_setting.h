#pragma once
#include "Scene_bass.h"

enum
{
	BLANC,
	KENSI,
	MAHOUTUKAi,
	SOURYO,
	TOUZOKU,
	ZYUKISI,
	BUSHI,
	GINYUSIZIN
};

class Scene_setting :public Scene_bass
{
	int background_image = 0;

public:
	//	スタメンのIDを入れる変数（4枠）
	int mem_ID[4];
	//	現在選択している枠
	int num = 0;
	
	bool charachenge_switch = 0;

	Scene_setting()
	{
	}
	void Init();
	void Update();
	void Render();
	void Exit();
};
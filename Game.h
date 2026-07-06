#pragma once

#include "main.h"

//　ゲームのシーン
enum {
	GAME_STATE_TITLE,		//　タイトル画面
	GAME_STATE_LEVEL,		//	難易度選択画面
	GAME_STATE_SETTING,		//　パーティー編成画面
	GAME_STATE_PLAY,		//　バトル画面
	GAME_STATE_END			//　終了画面
};

class Game
{
public:
	//	ゲームの状態
	int State;
	//	コンストラクタ
	Game() :State(GAME_STATE_TITLE)
	{
		void Init();
	}

	//	関数
	void Init();
	void Update();
	void Render();
	void Exit();
};


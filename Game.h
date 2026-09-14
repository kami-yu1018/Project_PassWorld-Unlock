#pragma once

//	ヘッダーファイルのインクルード
#include "main.h"
#include "Scene_title.h"
#include "Scene_level.h"
#include "Scene_setting.h"
#include "Scene_play.h"
#include "Scene_end.h"

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
	//	初期化状態（０：初期化されていない　１：初期化処理を完了している）
	bool init = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0;

	//	コンストラクタ
	Game() :State(GAME_STATE_TITLE)
	{
		void Init();
	}

	//	インスタンスの生成
	Scene_title		title_obj;
	Scene_level		level_obj;
	Scene_setting	set_obj;
	Scene_play		play_obj;
	Scene_end		end_obj;

	//	関数
	void Init();
	void Update();
	void Render();
	void Exit();
};


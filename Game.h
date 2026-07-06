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

//	関数
void GameInit();
void GameUpdate();
void GameRender();
void GameExit();
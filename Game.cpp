#include "Game.h"


//------------------------------------------------------------------------------
//	初期化処理
//------------------------------------------------------------------------------
void Game::Init()
{

}
//------------------------------------------------------------------------------
//	更新処理
//------------------------------------------------------------------------------
void Game::Update()
{
	switch (State)
	{
	case GAME_STATE_TITLE:		//　タイトル画面
		title_obj.Update();
		break;

	case GAME_STATE_LEVEL:	//　レベル選択画面	
		level_obj.Update();
		break;

	case GAME_STATE_SETTING:	//　パーティー編成画面
		set_obj.Update();
		break;

	case GAME_STATE_PLAY:		//	バトル画面
		play_obj.Update();
		break;

	case GAME_STATE_END:		//	終了画面
		end_obj.Update();
		break;
	}
}
//------------------------------------------------------------------------------
//	描画処理
//------------------------------------------------------------------------------
void Game::Render()
{
	switch (State)
	{
	case GAME_STATE_TITLE:		//　タイトル画面
		title_obj.Render();
		break;

	case GAME_STATE_LEVEL:		//　レベル選択画面	
		level_obj.Render();
		break;

	case GAME_STATE_SETTING:	//　パーティー編成画面
		set_obj.Render();
		break;

	case GAME_STATE_PLAY:		//	バトル画面
		play_obj.Render();
		break;

	case GAME_STATE_END:		//	終了画面
		end_obj.Render();
		break;
	}
}
//------------------------------------------------------------------------------
//	終了処理
//------------------------------------------------------------------------------
void Game::Exit()
{

}
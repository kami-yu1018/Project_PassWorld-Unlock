#include "Game.h"


//------------------------------------------------------------------------------
//	初期化処理
//------------------------------------------------------------------------------
void Game::Init()
{
	State = GAME_STATE_TITLE;
}
//------------------------------------------------------------------------------
//	更新処理
//------------------------------------------------------------------------------
void Game::Update()
{
	switch (State)
	{
	case GAME_STATE_TITLE:		//　タイトル画面
		if (init == 0)
		{
			title_obj.Init();	//	初期化処理
			init = 1;
		}
		title_obj.Update();		//	更新処理
		if (title_obj.next == 1)
		{
			State = GAME_STATE_LEVEL;
			init = 0;
		}
		break;

	case GAME_STATE_LEVEL:	//　レベル選択画面	
		if (init == 0)
		{
			level_obj.Init();	//	初期化処理
			init = 1;
		}
		level_obj.Update();
		if (level_obj.next == 1)
		{
			State = GAME_STATE_SETTING;
			init = 0;
		}
		break;

	case GAME_STATE_SETTING:	//　パーティー編成画面
		if (init == 0)
		{
			set_obj.Init();	//	初期化処理
			init = 1;
		}
		set_obj.Update();
		if (set_obj.next == 1)
		{
			State = GAME_STATE_PLAY;
			init = 0;
		}
		break;

	case GAME_STATE_PLAY:		//	バトル画面
		if (init == 0)
		{
			//	とりあえず適当な変数で埋めておく
			
			play_obj.Init(a,b,d,c,e);	//	初期化処理
			init = 1;
		}
		play_obj.Update();
		if (play_obj.next > 0)
		{
			State = GAME_STATE_END;
			init = 0;
		}
		break;

	case GAME_STATE_END:		//	終了画面
		end_obj.Update();
		if (end_obj.next == 1)
		{
			State = GAME_STATE_TITLE;
			init = 0;
		}
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
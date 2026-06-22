#include "main.h"

//------------------------------------------------------------------------------
//	WinMain
//------------------------------------------------------------------------------
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//===============================================
	//	初期化処理
	//===============================================
	//	ログの書き出しを無効化
	SetOutApplicationLogValidFlag(FALSE);

	//	ウィンドウモードの設定
	ChangeWindowMode(TRUE);

	//	ウィンドウサイズとカラービットの設定
	SetGraphMode(WINDOW_W, WINDOW_H, 32);

	//	ウィンドウのタイトル
	SetMainWindowText("PassWorld-Unlock");

	//	背景色の設定
	SetBackgroundColor(0, 0, 0);

	//	ＤＸライブラリの初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;		//	エラーが起きたら直ちに終了
	}

	//	ウィンドウ描画モード設定
	SetDrawScreen(DX_SCREEN_BACK);

	for (int i = 0; i < 256; ++i)
	{
		KeyFrame[i] = 0;
	}

	//===============================================
	//	ゲームループ
	//===============================================
	while (ProcessMessage() == 0)
	{
		GetHitKeyStateAll(key_buffer);

		for (int i = 0; i < 256; ++i)
		{
			if (key_buffer[i])
			{
				KeyFrame[i]++;
			}
			else
			{
				KeyFrame[i] = 0;
			}
		}

		//	リフレッシュレートを設定するための処理
		clock_t check_fps = clock() + CLOCKS_PER_SEC / 60;

		//	マウスカーソル表示設定
		SetMouseDispFlag(FALSE);

		//	printfDxの初期化
		clsDx();

		//	画面上の描画を初期化
		ClearDrawScreen();

		//	リフレッシュレートが一定になるまで待つ処理
		while(clock()<check_fps){}

		//	裏画面の描画を表に反映
		ScreenFlip();

		//	ループを抜ける

	}

	//===============================================
	//	終了処理
	//===============================================
	
	//	ＤＸライブラリ使用の終了処理
	DxLib_End();

	//	ソフトの終了
	return 0;
}

//------------------------------------------------------------------------------
//	キーを押した瞬間の処理
//------------------------------------------------------------------------------
bool PushHitKey(int key)
{
	if (KeyFrame[key] == 1)
	{
		return true;
	}
	return false;
}
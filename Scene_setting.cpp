#include "Scene_setting.h"

void Scene_setting::Init()
{
	//	背景画像の読み込み
	background_image = LoadGraph("data/picture/background.png");

	//	nextの初期化
	next = 0;

	//	初期のスタメンの設定
	mem_ID[0] = KENSI;
	mem_ID[1] = MAHOUTUKAi;
	mem_ID[2] = SOURYO;
	mem_ID[3] = TOUZOKU;
}

void Scene_setting::Update()
{
	//	左右キーで移動
	if (PushHitKey(KEY_INPUT_RIGHT))
	{
		num++;
		if (num > 4)
		{
			num = 0;
		}
	}
	if (PushHitKey(KEY_INPUT_LEFT))
	{
		num--;
		if (num < 0)
		{
			num = 3;
		}
	}
	//	スペースキーで決定
	if (PushHitKey(KEY_INPUT_RETURN) && num<4)
	{
		charachenge_switch = 1;
	}
	//	スタメン画面でエンターを押すと、キャラクター選択欄を表示

	//	キャラクター選択欄でエンターを押すと、現在選択しているキャラクターをスタメンに変更する
	//	すでにスタメンに入っているキャラクターは選択できないようにする

	//	スタートテキストのところでエンターを押したら、次のシーンへ進む
	//	現在確定している番号がScene_play.cppで生成される
	if (PushHitKey(KEY_INPUT_RETURN) && num == 4) 
	{
		next = 1;
	}

}

void Scene_setting::Render()
{
	//	背景
	DrawGraph(0, 0, background_image, TRUE);
	//	メンバーのビジュアル

	//	名前

	//	役職アイコン

	//	スタートテキスト
}

void Scene_setting::Exit()
{

}
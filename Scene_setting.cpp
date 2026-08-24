#include "Scene_setting.h"

void Scene_setting::Init()
{
	//	背景画像の読み込み
	background_image = LoadGraph("data/picture/background.png");
	//	プレイヤー画像の読み込み
	player_image[KENSI] = LoadGraph("data/picture/kensi.png");
	player_image[MADOUSI] = LoadGraph("data/picture/madousi.png");
	player_image[SOURYO] = LoadGraph("data/picture/souryo.png");
	player_image[TOUZOKU] = LoadGraph("data/picture/touzoku.png");
	player_image[ZYUKISI] = LoadGraph("data/picture/zyukisi.png");
	player_image[BUSHI] = LoadGraph("data/picture/bushi.png");
	player_image[GINYUSIZIN] = LoadGraph("data/picture/ginyusizin.png");

	//	nextの初期化
	next = 0;

	//	初期のスタメンの設定
	mem_ID[0] = KENSI;
	mem_ID[1] = MADOUSI;
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

	int box_x = 130;
	int box_y = 250;
	DrawBox(box_x + (350 * num), box_y, box_x + (307 + (350 * num)), box_y+460, GetColor(0, 0, 255), TRUE);

	//	メンバーのビジュアル
	for(int i=0;i<4;++i)
	{
		DrawExtendGraph(0+(350*i)+130, 0+250, 307+(350*i)+130, 460+250, player_image[mem_ID[i]], TRUE);
	}
	//	名前

	//	役職アイコン

	//	スタートテキスト
}

void Scene_setting::Exit()
{

}
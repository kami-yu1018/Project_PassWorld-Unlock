#include "Scene_level.h"

void Scene_level::Init()
{		   
	//	背景画像の読み込み
	background_image = LoadGraph("data/picture/background.png");

	level_image[0] = LoadGraph("data/picture/easy.png");
	level_image[1] = LoadGraph("data/picture/normal.png");
	level_image[2] = LoadGraph("data/picture/hard.png");

	//	nextの初期化
	next = 0;
	//	最初に表示する難易度はeasy
	lv = 0;
}		   
		   
void Scene_level::Update()
{		   
	//	上下キーで難易度の変更
	if (PushHitKey(KEY_INPUT_LEFT))
	{
		//	上に行くほど低難易度なのでレベルを減らす
		lv--;
		//	easy以下に行ってしまったら
		if (lv < 0)
		{
			//	hardに移動させる
			lv = 2;
		}
		
	}
	if (PushHitKey(KEY_INPUT_RIGHT))
	{
		//	下に行くほど高難易度にするのでレベルを増やす
		lv++;
		//	hard以上になった場合
		if (lv > 2)
		{
			//	easyに戻る
			lv = 0;
		}

	}

	//	エンターを押したら難易度を確定
	//	（Scene_playで難易度を渡せるようにする）
	if (PushHitKey(KEY_INPUT_RETURN))
	{
		next = 1;
	}
}		   
		   
void Scene_level::Render()
{	
	//	背景
	DrawGraph(0, 0, background_image, TRUE);
	//	難易度の画像
	for(int i=0;i<3;++i)
	{
		if (lv == i) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		else SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);

		DrawGraph(100 + (500 * i), 100, level_image[i], TRUE);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}		   
		   
void Scene_level::Exit()
{

}
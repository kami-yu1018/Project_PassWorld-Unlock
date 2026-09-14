#include"Scene_end.h"

void Scene_end::Init()
{
	//	画像の読み込み
	end_image[0] = LoadGraph("data/picture/GameClear.png");
	end_image[1] = LoadGraph("data/picture/GameOver.png");

	//	nextの初期化
	next = 0;
}

void Scene_end::Update()
{
	//	キーを押したら次のシーンへ
	if (PushHitKey(KEY_INPUT_RETURN))
	{
		next = 1;
	}
}

void Scene_end::Render(int end)
{
	//	引数からそれぞれのエンディング画像を描画
	//	ゲームクリア
	if (end == 1)
	{
		DrawGraph(0, 0, end_image[0], TRUE);
		DrawString(800, 600, "Push Enter to Title", GetColor(255, 255, 255));

	}

	//	ゲームオーバー
	else if (end == 2)
	{
		DrawGraph(0, 0, end_image[1], TRUE);
		DrawString(800, 600, "Push Enter to Title", GetColor(255, 255, 255));
	}

}

void Scene_end::Exit()
{

}
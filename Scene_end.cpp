#include"Scene_end.h"

void Scene_end::Init()
{
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
		//	どこのシーンか（要消去）
		DrawString(100, 100, "clear", GetColor(25, 255, 255));
	}

	//	ゲームオーバー
	else if (end == 2)
	{
		//	どこのシーンか（要消去）
		DrawString(100, 100, "gameover", GetColor(25, 255, 255));
	}

}

void Scene_end::Exit()
{

}
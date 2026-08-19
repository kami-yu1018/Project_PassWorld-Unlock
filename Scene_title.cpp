#include "Scene_title.h"

void Scene_title::Init()
{
	title_image = LoadGraph("data/picture/title.png");
	//	nextの初期化
	next = 0;
}

void Scene_title::Update()
{
	//	キーを押したら次のシーンへ移動
	if (PushHitKey(KEY_INPUT_RETURN))
	{
		next = 1;
	}

}

void Scene_title::Render()
{
	//	背景
	DrawGraph(0, 0, title_image,TRUE);
	//	"Push -Key To Start"のテキスト
	DrawString(700, 800, "Push Enter To Start",GetColor(255,255,255));

}

void Scene_title::Exit()
{

}
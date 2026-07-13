#include "Scene_title.h"

void Scene_title::Init()
{
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

	//	タイトル
	DrawString(100, 100, "title", GetColor(255, 255, 255));
	//	"Push -Key To Start"のテキスト


}

void Scene_title::Exit()
{

}
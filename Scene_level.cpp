#include "Scene_level.h"

void Scene_level::Init()
{		   
	//	nextの初期化
	next = 0;
}		   
		   
void Scene_level::Update()
{		   
	//	上下キーで難易度の変更

	//	選択している難易度でshiftキーを押すと、敵のビジュアルと説明を表示

	//	エンターを押したら難易度を確定
	//	（Scene_playで難易度を渡せるようにする）
	if (PushHitKey(KEY_INPUT_RETURN))
	{
		next = 1;
	}
}		   
		   
void Scene_level::Render()
{	
	//	どこのシーンか（要消去）
	DrawString(100, 100, "level", GetColor(25, 255, 255));

	//	背景

	//	難易度の画像
}		   
		   
void Scene_level::Exit()
{

}
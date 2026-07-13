#include "Scene_setting.h"

void Scene_setting::Init()
{
	//	nextの初期化
	next = 0;

	//	初期のスタメンの設定

}

void Scene_setting::Update()
{
	//	左右キーで移動

	//	エンターキーで決定

	//	スタメン画面でエンターを押すと、キャラクター選択欄を表示

	//	キャラクター選択欄でエンターを押すと、現在選択しているキャラクターをスタメンに変更する
	//	すでにスタメンに入っているキャラクターは選択できないようにする

	//	スタートテキストのところでエンターを押したら、次のシーンへ進む
	//	現在確定している番号がScene_play.cppで生成される
	if (PushHitKey(KEY_INPUT_RETURN)) 
	{
		next = 1;
	}

}

void Scene_setting::Render()
{
	//	どこのシーンか（要消去）
	DrawString(100, 100, "setting", GetColor(25, 255, 255));

	//	背景
	
	//	メンバーのビジュアル

	//	名前

	//	役職アイコン

	//	スタートテキスト
}

void Scene_setting::Exit()
{

}
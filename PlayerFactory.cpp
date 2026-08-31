#include "Factory.h"
#include "Player.h"

//　プレイヤーデータは不変（基礎ステータスは不変でレベルによって数値変動する）なので静的で定義する
const PlayerData PlayerFactory::PlayerTable[] = {
	{1,"剣士",70,25,22,18,15, 14,2,5,3,2,
		{
			{0,"火炎切り","fslash",1.2,TYPE_ATTACK},		//	単体攻撃
			{1,"クロスブレイク","xbreak",1.7,TYPE_ATTACK},	//	単体２連攻撃
			{2,"奥義・蒼天斬","secret_skybreak",2.4,TYPE_ATTACK}	//	単体特大ダメージ攻撃
		}
	},
	{2,"魔法使い",45,60,25,8,14, 8,6,5,1,2,
		{
			{0,"ファイアボール","ball_f",1.3,TYPE_ATTACK},		//	単体攻撃
			{1,"ライトニングスパーク","lightvolt",2.0,TYPE_ATTACK},		//	全体攻撃
			{2,"アストラルノヴァ","extream_nova",3.0,TYPE_ATTACK}		//	全体特大攻撃
		}
	},
	{3,"僧侶",50,75,15,12,12, 9,7,3,2,1,
		{
			{0,"キュアー","cure",1.5,TYPE_HEAL},		//	単体回復
			{1,"ホーリーレイ","holy_rain",1.2,TYPE_HEAL},	//	全体回復
			{2,"リザレクション","praytogod_resurrection",2.2,TYPE_HEAL}	//	復活呪文
		}
	},
	{4,"盗賊",50,30,20,10,25, 8,3,4,2,4,
		{
			{0,"クイックスタブ","quick",1.0,TYPE_ATTACK},	//	全体攻撃
			{1,"盗賊乱舞","randtheaf",0.9,TYPE_ATTACK},		//	ランダム８連攻撃
			{2,"秘儀・アサシングリード","assassin_deadend",2.7,TYPE_ATTACK}		//	確率即死攻撃
		}
	},
	{5,"重騎士",110,15,20,30, 5,20,1,4,6,1,
		{
			{0,"シールドバニッシュ","banish",1.3,TYPE_DEF},	//	単体攻撃、全体防御強化
			{1,"不屈の甲冑","presis_armor",2.0,TYPE_DEF},	//	単体強化＆ターゲット化
			{2,"不落の鉄壁","no_break_irondefense",5.0,TYPE_DEF}	//	単体バリア
		}
	},
	{6,"武士",65,20,28,14,20, 13,2,6,2,3,
		{
			{0,"居合切り","iai",1.4,TYPE_ATTACK},
			{1,"桜花一閃","cherry_one",2.0,TYPE_ATTACK},
			{2,"桜家秘刀・散華満月","secretblead_fullmoonbloom",3.2,TYPE_ATTACK}
		}
	},
	{7,"吟遊詩人",55,50,12,14,18, 10,5,2,2,2,
		{
			{0,"マーチングメロディ","melo_marching",1.3,TYPE_BUF},	//	味方攻撃力バフ
			{1,"シャドウメロディ","melo_shadow",0.8,TYPE_BUF},		//	敵攻撃力デバフ
			{2,"戯曲・FreedomWorld","act_freedom_world_all",1.5,TYPE_BUF}	//	全体バフ
		}
	}
};

//　変数、関数がメモリ上で占有するサイズで割ってデータテーブルのサイズを求める
const int PlayerFactory::PlayerTableSize = sizeof(PlayerTable) / sizeof(PlayerData);

Player* PlayerFactory::CreatePlayer(int ID)
{
	for (int i = 0; i < PlayerTableSize; ++i)
	{
		if (PlayerTable[i].ID == ID)
		{
			return new Player(PlayerTable[i]);
		}
	}
	return nullptr;
}
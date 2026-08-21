#include "Factory.h"
#include "Player.h"

//　プレイヤーデータは不変（基礎ステータスは不変でレベルによって数値変動する）なので静的で定義する
const PlayerData PlayerFactory::PlayerTable[] = {
	{1,"剣士",70,25,22,18,15, 14,2,5,3,2},
	{2,"魔法使い",45,60,25,8,14, 8,6,5,1,2},
	{3,"僧侶",50,75,15,12,12, 9,7,3,2,1},
	{4,"盗賊",50,30,20,10,25, 8,3,4,2,4},
	{5,"重騎士",110,15,20,30, 5,20,1,4,6,1},
	{6,"武士",65,20,28,14,20, 13,2,6,2,3},
	{7,"吟遊詩人",55,50,12,14,18, 10,5,2,2,2}
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
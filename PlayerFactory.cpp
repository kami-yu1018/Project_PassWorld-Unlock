#include "Factory.h"
#include "Player.h"

//　プレイヤーデータは不変（基礎ステータスは不変でレベルによって数値変動する）なので静的で定義する
const PlayerData PlayerFactory::PlayerTable[] = {
	{1,"剣士",100,80,100,100,75},
	{2,"魔法使い",80,120,100,80,60},
	{3,"僧侶",80,120,50,80,50},
	{4,"盗賊",70,50,75,60,100},
	{5,"重騎士",135,50,80,150,30},
	{6,"武士",75,50,100,75,70},
	{7,"吟遊詩人",75,80,50,75,80}
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
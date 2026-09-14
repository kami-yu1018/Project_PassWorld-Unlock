#include "Factory.h"
#include "Enemy.h"

// 敵データは不変なので静的で定義する
const EnemyData EnemyFactory::EnemyTable[] = {
	{1,"スライム",120,30,18,12,8},
	{2,"ゴブリン",180,40,27,18,14},
	{3,"魔導ゴーレム",350,80,35,40,6}
};

// 変数、関数がメモリ上で占有するサイズで割ってデータテーブルのサイズを求める
const int EnemyFactory::EnemyTableSize = sizeof(EnemyTable) / sizeof(EnemyData);

Enemy* EnemyFactory::CreateEnemy(int ID)
{
	for (int i = 0; i < EnemyTableSize; i++)
	{
		if (EnemyTable[i].ID == ID)
		{
			return new Enemy(EnemyTable[i]);
		}
	}
	return nullptr;
}

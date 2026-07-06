#include "Factory.h"
#include "Enemy.h"

// 敵データは不変なので静的で定義する
const EnemyData EnemyFactory::EnemyTable[] = {
	{1,"スライム",50,30,20,10,5},
	{2,"ゴブリン",80,50,30,20,10},
	{3,"オーク",120,80,50,30,20},
	{4,"ドラゴン",200,150,100,80,50},
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

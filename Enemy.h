#pragma once
#include"Data.h"

// @brief 敵クラス
// 敵のステータスや行動を管理するクラス
class Enemy
{
public:
	// EnemyData構造体
	EnemyData Data;
	// コンストラクタ
	Enemy(const EnemyData&data):Data(data)
	{ 
	}
};
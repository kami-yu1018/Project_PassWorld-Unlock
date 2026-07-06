#pragma once
#include"Data.h"

class Player;
class Enemy;

// @brief プレイヤーの生成を担当するファクトリークラス
class PlayerFactory
{
	//　プレイヤーのデータを格納するテーブル
	static const PlayerData PlayerTable[];
	//　プレイヤーのデータテーブルサイズ
	static const int PlayerTableSize;

public:
	//　指定されたIDに基づいてプレイヤーを生成
	//	@param ID 生成するプレイヤーのID
	//	@return 生成されたプレイヤーのポインタ
	//	IDが見つからなかった場合はnullptrを返す
	static Player* CreatePlayer(int ID);
};

// @brief 敵の生成を担当するファクトリークラス
class EnemyFactory
{
	//	敵のデータを格納するテーブル
	static const EnemyData EnemyTable[];
	//　敵のデータテーブルサイズ
	static const int EnemyTableSize;

public:
	//　指定されたIDに基づいて敵を生成
	//	@param ID 生成する敵のID
	//	@return 生成された敵のポインタ
	//	IDが見つからなかった場合はnullptrを返す
	static Enemy* CreateEnemy(int ID);
};
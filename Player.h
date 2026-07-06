#pragma once
#include "Data.h"

// @brief プレイヤークラス
// プレイヤーのステータスや行動を管理するクラス
class Player
{
public:
	// PlayerData構造体
	PlayerData Data;

	// コンストラクタ
	Player(const PlayerData& data) :Data(data)
	{
	}
};
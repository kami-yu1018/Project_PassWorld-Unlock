#pragma once
#include<string>

// プレイヤーのデータ構造体
struct PlayerData
{
	int ID;
	const char Name[256];
	int hp;
	int mp;
	int atk;
	int def;
	int spd;
};


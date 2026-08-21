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

	int g_hp;
	int g_mp;
	int g_atk;
	int g_def;
	int g_spd;
};

//	敵のデータ構造体
struct EnemyData
{
	int ID;
	const char Name[256];
	int hp;
	int mp;
	int atk;
	int def;
	int spd;
	int exp;
};
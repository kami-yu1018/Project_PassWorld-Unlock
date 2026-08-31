#pragma once
#include<string>

//	スキル数
constexpr int SKILL_COUNT = 3;

enum
{
	TYPE_ATTACK,
	TYPE_DEF,
	TYPE_HEAL,
	TYPE_BUF,
};

//	スキルデータ
struct SkillData
{
	int ID;
	const char* name;		//	スキル名
	const char* password;	//	パスワード
	float Rate;				//	倍率
	int ratetype;			//	効果タイプ
};

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

	SkillData skills[SKILL_COUNT];
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
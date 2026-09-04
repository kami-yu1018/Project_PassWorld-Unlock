#pragma once
#include<string>

//	スキル数
constexpr int SKILL_COUNT = 3;

enum EffectType
{
	TYPE_ATTACK,
	TYPE_DEF,
	TYPE_HEAL,
	TYPE_BUF,
};

enum TargetType
{
	TARGET_ENEMY_ONE,
	TARGET_ENEMY_ALL,
	TARGET_ENEMY_RANDOM,
	TARGET_PLAYER_ONE,
	TARGET_PLAYER_ALL,
};

//	スキルデータ
struct SkillData
{
	int ID;
	const char* name;		//	スキル名
	const char* password;	//	パスワード
	float Rate;				//	倍率
	EffectType effect;		//	効果タイプ
	TargetType target;
	int durationTurn;		//	バフの効果ターン
	int hitCount;			//	攻撃回数
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
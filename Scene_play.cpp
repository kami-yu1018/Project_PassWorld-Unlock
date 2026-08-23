#include "Main.h"
#include "Scene_play.h"


//------------------------------------------------------------------------------
//　初期化処理
//------------------------------------------------------------------------------
void Scene_play::Init(int level, int p_1, int p_2, int p_3, int p_4)
{
	//	nextの初期化
	next = 0;

	int level;	//	難易度によるプレイヤーのレベル用の変数

	
	//	レベルから敵を生成
	switch (level)
	{
	case 0:
		enemy[0] = EnemyFactory::CreateEnemy(1);
		enemy[1] = EnemyFactory::CreateEnemy(2);
		enemy[2] = EnemyFactory::CreateEnemy(3);

		enemy_num = 3;

		break;
	case 1:
		break;
	case 2:
		break;
	}
	
	//	プレイヤーIDからプレイヤーを生成
	player[0] = PlayerFactory::CreatePlayer(p_1);
	player[1] = PlayerFactory::CreatePlayer(p_2);
	player[2] = PlayerFactory::CreatePlayer(p_3);
	player[3] = PlayerFactory::CreatePlayer(p_4);
	
	for(int i=0;i<4;++i)
	{
		player[i]->Data.hp = player[i]->Data.hp + player[i]->Data.g_hp * level;
		player[i]->Data.mp = player[i]->Data.mp + player[i]->Data.g_mp * level;
		player[i]->Data.atk = player[i]->Data.atk + player[i]->Data.g_atk * level;
		player[i]->Data.def = player[i]->Data.def + player[i]->Data.g_def * level;
		player[i]->Data.spd = player[i]->Data.spd + player[i]->Data.g_spd * level;
	}

	//	プレイヤーと敵のSPDを見て、順番を決める
	CreateTurn(enemy_num);
}
//------------------------------------------------------------------------------
// 　更新処理
//------------------------------------------------------------------------------
void Scene_play::Update()
{
	//	現在の順番を見る
	TurnActor actor = turnOrder[TurnIndex];


	//	敵の場合
	if(actor.isEnemy)
	{
		//	ランダムなターゲティング
		int random = GetRand(4);
		//	攻撃

			//	ダメージ計算
	}


	//	プレイヤーの場合
	else
	{
		//	行動の選択（上下キー）

		//	スキルを選択したらスキルの選択

		//	ターゲット選択

		//	パスワードの入力

		//	攻撃

			//	ダメージの計算

	}

		



	//	敵全員のHPが０になったらプレイヤーの勝利
	if (PushHitKey(KEY_INPUT_1))
	{
		next = 1;
	}
	//	プレイヤー全員のHPが０になったら敗北
	if (PushHitKey(KEY_INPUT_2))
	{
		next = 2;
	}
}
//------------------------------------------------------------------------------
// 　描画処理
//------------------------------------------------------------------------------
void Scene_play::Render()
{
	//	どこのシーンか（要消去）
	DrawString(100, 100, "play", GetColor(25, 255, 255));

	//	背景

	//	敵キャラクター

	//	味方

	//	HP,MP,APP

	//	ターゲット（攻撃前のみ）

	//	カットイン（攻撃時のみ）
}
//------------------------------------------------------------------------------
// 　終了処理
//------------------------------------------------------------------------------
void Scene_play::Exit()
{

}


//	SPDからターンを決める処理
void Scene_play::CreateTurn(int enemy_num)
{
	//	味方の登録
	for (int i = 0; i < player_count; ++i)
	{
		turnOrder[i] = { false,i };
	}
	//	敵の登録
	for (int i = 0; i < enemy_num; ++i)
	{
		turnOrder[player_count + i] = { true,i };
	}

	//	SPDの高い順に並べ替え
	int act_count = player_count + enemy_num;
	for (int i = 0; i < act_count; ++i)
	{
		for (int j = i + 1; j < act_count; ++j)
		{
			int spd1 = turnOrder[i].isEnemy
				? enemy[turnOrder[i].index]->Data.spd
				: player[turnOrder[i].index]->Data.spd;

			int spd2 = turnOrder[j].isEnemy
				? enemy[turnOrder[i].index]->Data.spd
				: player[turnOrder[i].index]->Data.spd;

			if (spd1 < spd2)
			{
				TurnActor temp = turnOrder[i];
				turnOrder[i] = turnOrder[j];
				turnOrder[j] = temp;
			}
		}
	}
	TurnIndex = 0;
}

//	生きているキャラクターを探しながら次に進める
void Scene_play::NextTurn(int enemy_num)
{
	bool IsAlive[7];
	for (int i = 0; i < player_count; ++i)
	{
		IsAlive[i] = p_alive[i];
	}
	for (int i = player_count; i < player_count + enemy_num; ++i)
	{
		IsAlive[i] = e_alive;
	}

	do
	{
		TurnIndex = (TurnIndex + 1) % actor_count;
	} while (!IsAlive[TurnIndex]);
}
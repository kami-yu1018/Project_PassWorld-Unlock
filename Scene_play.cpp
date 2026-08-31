#include "Main.h"
#include "Scene_play.h"


//------------------------------------------------------------------------------
//　初期化処理
//------------------------------------------------------------------------------
void Scene_play::Init(int level, int p_1, int p_2, int p_3, int p_4)
{
	//	背景画像の読み込み
	background = LoadGraph("data/picture/battle_field.png");

	//	nextの初期化
	next = 0;

	int p_lv;

	//	レベルから敵を生成
	switch (level)
	{
	case 0:
		enemy[0] = EnemyFactory::CreateEnemy(1);
		enemy[1] = EnemyFactory::CreateEnemy(2);
		enemy[2] = EnemyFactory::CreateEnemy(3);

		enemy_num = 3;

		p_lv = 10;
		break;
	case 1:
		enemy[0] = EnemyFactory::CreateEnemy(1);
		enemy[1] = EnemyFactory::CreateEnemy(2);
		enemy[2] = EnemyFactory::CreateEnemy(3);

		enemy_num = 3;
		p_lv = 40;
		break;
	case 2:
		enemy[0] = EnemyFactory::CreateEnemy(1);
		enemy[1] = EnemyFactory::CreateEnemy(2);
		enemy[2] = EnemyFactory::CreateEnemy(3);

		enemy_num = 3;

		p_lv = 70;

		break;
	}
	
	//	プレイヤーIDからプレイヤーを生成
	player[0] = PlayerFactory::CreatePlayer(p_1);
	player[1] = PlayerFactory::CreatePlayer(p_2);
	player[2] = PlayerFactory::CreatePlayer(p_3);
	player[3] = PlayerFactory::CreatePlayer(p_4);
	
	for(int i=0;i<4;++i)
	{
		player[i]->Data.hp = player[i]->Data.hp + player[i]->Data.g_hp * p_lv;
		player[i]->Data.mp = player[i]->Data.mp + player[i]->Data.g_mp * p_lv;
		player[i]->Data.atk = player[i]->Data.atk + player[i]->Data.g_atk * p_lv;
		player[i]->Data.def = player[i]->Data.def + player[i]->Data.g_def * p_lv;
		player[i]->Data.spd = player[i]->Data.spd + player[i]->Data.g_spd * p_lv;
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

	//	フラグのみを更新（Render側で使うため）
	currentIsEnemy = actor.isEnemy;
	nowID = actor.index;

	//	敵の場合
	if(actor.isEnemy)
	{
		//	ランダムなターゲティング
		int random = GetRand(4);
		//	攻撃
		
			//	ダメージ計算

		/////////////////////////////////////////////////////
		
	}


	//	プレイヤーの場合
	else
	{
		//	エンター入力処理
		switch (player_select)
		{
		case SELECT_MOVE:
			//	エンターキーを押したら次に進む
			if (PushHitKey(KEY_INPUT_RETURN))
			{
				switch (player_move)
				{
				case NOMAL_ATTACK:
					player_select = SELECT_TARGET;
					break;
				case SKILL:
					player_select = SELECT_SKILL;
					break;
				case GURD:
					player_select = SELECT_GURD;
					break;
				}
			}
			break;
			
		case SELECT_SKILL:
			if (PushHitKey(KEY_INPUT_RETURN))
			{
				player_select = SELECT_TARGET;
			}
			break;

		case SELECT_TARGET:
			//	エンターを押したら次
			if (PushHitKey(KEY_INPUT_RETURN))
			{
				switch (player_move)
				{
				case NOMAL_ATTACK:
					player_select = ATTACK;
					break;

				case SKILL:
					player_select = PASSWORD;
					passwordInputHandle = MakeKeyInput
					(31,
						FALSE,
						FALSE,
						FALSE
					);
					SetActiveKeyInput(passwordInputHandle);

					break;
				}
			}
			break;
			
		case PASSWORD:
			if (PushHitKey(KEY_INPUT_RETURN))
			{
				player_select = ATTACK;
			}

			break;
			
		case ATTACK:
			
			break;

		case SELECT_GURD:
			break;
		}


		switch(player_select)
		{
		case SELECT_MOVE:
			//	行動の選択（上下キー）
			if (PushHitKey(KEY_INPUT_UP))
			{
				player_move--;
				if (player_move < 0)
				{
					player_move = 2;
				}
			}
			if (PushHitKey(KEY_INPUT_DOWN))
			{
				player_move++;
				if (player_move > 2)
				{
					player_move = 0;
				}
			}
			break;

			//	行動を選択したらスキルの選択
		case SELECT_SKILL:
			//	行動の選択（上下キー）
			if (PushHitKey(KEY_INPUT_UP))
			{
				skill_num--;
				if (skill_num < 0)
				{
					skill_num = 2;
				}
			}
			if (PushHitKey(KEY_INPUT_DOWN))
			{
				skill_num++;

				if (skill_num > 2)
				{
					skill_num = 0;
				}
			}
			
			break;

			//	ターゲット選択
		case SELECT_TARGET:
			if (PushHitKey(KEY_INPUT_UP))
			{
				// 先に安全にデクリメントしてから配列参照
				do {
					target = (target - 1 + 3) % 3; // 0..2 にラップ
				} while (e_alive[target]); // 生存している敵を選ぶなら ! -> false をスキップ
				
			}
			if (PushHitKey(KEY_INPUT_DOWN))
			{
				do {
					target = (target + 1) % 3;
				} while (e_alive[target]);
				
			}
			break;

			//	パスワードの入力
		case PASSWORD:
			if (CheckKeyInput(passwordInputHandle) == 0)
			{
				GetKeyInputString(inputPassword, passwordInputHandle);

				const SkillData& skill = player[actor.index]->Data.skills[skill_num];

				passwordCorrect = std::strcmp(inputPassword, skill.password) == 0;
				rate = passwordCorrect ? skill.Rate : 0.5f;
			}

			break;
			//	攻撃
		case ATTACK:
			switch (player_move)
			{
			case NOMAL_ATTACK:
				enemy[target]->Data.hp -= CaluculateDamage(player[actor.index]->Data.atk, enemy[target]->Data.def);
				damage_text= CaluculateDamage(player[actor.index]->Data.atk, enemy[target]->Data.def);
				break;
			case SKILL:
				int bassDamage = CaluculateDamage(player[actor.index]->Data.atk, enemy[target]->Data.def);
				damage_text = static_cast<int>(bassDamage * rate);
				enemy[target]->Data.hp -= damage_text;
					
				DeleteKeyInput(passwordInputHandle);
				passwordInputHandle = -1;
				
				break;
			}

			break;

		case SELECT_GURD:
			break;
		}


		//////////////////////////////////////////////////////
		
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
	//	背景
	DrawGraph(0, 0, background, TRUE);
	//	敵キャラクター

	//	味方
	DrawRectGraph(300, 300, 0,0,1024,1024, set_obj.player_image[player[0]->Data.ID], TRUE, FALSE);
	//	HP,MP,APP

	//	ターゲット（攻撃前のみ）

	//	カットイン（攻撃時のみ）


	///////////////////////////////////////////////////////////////
	//	確認テキスト
	if(enemy[0]!=nullptr)
	{
		DrawFormatString(100, 100, GetColor(255, 255, 255), "%s、%s、%sが現れた！", 
			enemy[0]->Data.Name,enemy[1]->Data.Name,enemy[2]->Data.Name);
	}

	if (currentIsEnemy)
	{
		DrawString(100, 120, "敵のターン", GetColor(255, 255, 255));
	}
	else
	{
		DrawString(100, 120, "味方のターン", GetColor(255, 255, 255));
		DrawFormatString(250, 120, GetColor(255, 255, 255), "%s", player[nowID]->Data.Name);
	}

	if (!currentIsEnemy)
	{
		
		switch (player_select)
		{
		case SELECT_MOVE:
			switch (player_move)
			{
			case NOMAL_ATTACK:
				DrawString(100, 140, "攻撃", GetColor(255, 255, 255));
				break;
			case SKILL:
				DrawString(100, 140, "スキル", GetColor(255, 255, 255));
				break;
			case GURD:
				DrawString(100, 140, "防御", GetColor(255, 255, 255));
				break;
			}
			break;
			//	行動を選択したらスキルの選択
		case SELECT_SKILL:
			DrawFormatString(100, 140, GetColor(255, 255, 255), "スキルを選択してください：%s",player[nowID]->Data.skills[skill_num].name);
			break;
			//	ターゲット選択
		case SELECT_TARGET:
			DrawFormatString(100, 140, GetColor(255, 255, 255), "ターゲットを選択してください:%s", enemy[target]->Data.Name);
			break;
			//	パスワードの入力
		case PASSWORD:
			DrawFormatString(100, 140, GetColor(255, 255, 255), "パスワードを入力：%s", inputPassword);
			break;
			//	攻撃
		case ATTACK:
			switch (player_move)
			{
			case NOMAL_ATTACK:
				DrawString(100, 140, "攻撃", GetColor(255, 255, 255));
				DrawFormatString(100, 160, GetColor(255, 255, 255), 
					"%s に %d ダメージ！",
					enemy[target]->Data.Name, 
					damage_text);
				break;
			case SKILL:
				DrawString(100, 140, "a", GetColor(255, 255, 255));
				break;
			case GURD:
				DrawString(100, 140, "防御", GetColor(255, 255, 255));
				break;
			}

			break;

		case SELECT_GURD:
			break;
		}
	}
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
				? enemy[turnOrder[j].index]->Data.spd
				: player[turnOrder[j].index]->Data.spd;

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
	bool IsAlive[actor_count];
	for (int i = 0; i < player_count; ++i)
	{
		IsAlive[i] = p_alive[i];
	}
	for (int i = player_count; i < player_count + enemy_num; ++i)
	{
		IsAlive[i] = e_alive[i - player_count];
	}

	do
	{
		TurnIndex = (TurnIndex + 1) % actor_count;
	} while (!IsAlive[TurnIndex]);
}
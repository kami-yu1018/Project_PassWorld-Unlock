#include<algorithm>
#include<random>

int CalculateDamage(int actor_ATK, int target_DEF)
{
	//	攻撃する側の攻撃力とターゲットの防御力からダメージを計算
	//	最低でも１ダメージは入るようにする
	const int damage = (std::max)(1, actor_ATK - target_DEF);

	return damage;
}
#pragma once
#include"Player.h"
#include"Monster.h"
enum class BattleResult
{
	LOSE = 0,
	WIN = 1,
	ERROR = 2
};
class BattleManager
{
public:
	BattleResult MonsterBattle(Player* player, Actor* monster);
	BattleResult BossBattle(Player* player, Actor* monster);
};


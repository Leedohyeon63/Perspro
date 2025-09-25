#pragma once
#include"Player.h"
#include"Monster.h"
#include "Inventory.h"
enum class BattleResult
{
	LOSE = 0,
	WIN = 1,
	ERROR = 2,
	RUN =3
};
class BattleManager
{
public:

	BattleResult MonsterBattle(Player* player, Actor* monster, Inventory* inventory);
	BattleResult BossBattle(Player* player, Actor* boss, Inventory* inventory);
	bool MonsterFight(Player* player, Actor* monster, Inventory* inventory);
	bool BossFight(Player* player, Actor* boss, Inventory* inventory);
protected:
	string Item;
	Inventory inven;
	bool SkillUsed = false;
	int MonsterTurnCounter = 0;
};


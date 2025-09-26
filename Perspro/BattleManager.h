#pragma once
#include"Player.h"
#include"Monster.h"
#include "Inventory.h"
//전투를 관리하는 클래스
enum class BattleResult
{//전투 결과를 나타내는 enum 클래스
	LOSE = 0,
	WIN = 1,
	ERROR = 2,
	RUN =3
};
class BattleManager
{
public:

	BattleResult MonsterBattle(Player* player, Actor* monster, Inventory* inventory);//몬스터와 보스랑 싸우는 함수들
	BattleResult BossBattle(Player* player, Actor* boss, Inventory* inventory);
	bool MonsterFight(Player* player, Actor* monster, Inventory* inventory);
	bool BossFight(Player* player, Actor* boss, Inventory* inventory);//여기까지
protected:
	//전투 제어 관련 변수
	string Item;
	Inventory inven;
	bool SkillUsed = false;
	int MonsterTurnCounter = 0;
};


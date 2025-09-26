#pragma once
#include "StageMap.h"
#include "Player.h"
#include "Inventory.h"
#include "Shop.h"
#include "Mosterlist.h"
#include "Monster.h"
#include "CreateMonster.h"
#include "BattleManager.h"

#include<random>
//게임의 전반을 담당하는 클래스
class GameManager
{
public:
	void TextRpg();
	void Nextstage();
	void BattleEvent(int Stage);
	void BossBattlevnet(int Stage);
	GameManager();
	~GameManager();
private:
	bool Isdead = false;
	bool IsClear = false;
	int StageTrigger = 1;
	const int MAxstage = 6;
	bool BossClear = false;
	string move;
	Player player;
	StageMap map;
	Actor* CurrentMonster = nullptr;
	Actor* CurrentBoss = nullptr;
	Inventory inven;
	Shop shop;
	BattleManager battleManager;
};



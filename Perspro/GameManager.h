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

class GameManager
{
public:
	void TextRpg();
	void Nextstage();
	void BattleEvent(int Stage);
	GameManager();
	~GameManager();
private:
	bool Isdead = false;
	int StageTrigger = 1;
	const int MAxstage = 5;
	string move;
	Player player;
	StageMap map;
	Actor* CurrentMonster = nullptr;
	Inventory inven;
	Shop shop;
	BattleManager battleManager;
};



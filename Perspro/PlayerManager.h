#pragma once
#include"Actor.h"
#include "StageMap.h"
class PlayerManager : public Actor, public StageMap
{
public:
	StageMap stagemap;
	int PlayerPosx = 0;
	int PlayerPosy = 0;
	void move(string move, int stage);
	void PlayerDmagetaken(int Dam);
	void PlayerHealing(int Heal);
	void PlayerGetMoney(int gold);
	PlayerManager()=default;
	PlayerManager(const char* InName, int HP, int Dam);
	~PlayerManager();
};


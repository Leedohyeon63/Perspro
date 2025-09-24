#pragma once
#include"Actor.h"
#include "StageMap.h"
class Player : public Actor
{
public:
	StageMap stagemap;
	int PlayerPosx = 0;
	int PlayerPosy = 0;
	void move(string move, int stage);
	void PlayerDmagetaken(int Dam);
	void PlayerHealing(int Heal);
	void PlayerGetMoney(int gold);
	void PlayerDmageSet(int Atk);
	Player()=default;
	Player(const char* InName,int HP, int Dam, int Level);
	~Player();
};


#pragma once
#include"Actor.h"
class Player : public Actor
{
public:

	int PlayerPosx = 0;
	int PlayerPosy = 0;
	void move(int x, int y);
	void PlayerDmagetaken(int Dam);
	void Healing(int Heal);
	Player(const char* InName, int HP, int Dam);
	~Player();
};


#pragma once
#include"Actor.h"
class Boss : public Actor
{
public:
	void BossAttack();
	void Bossinfo();
	void BossDamgeTaken(int Dam);
protected:
	Boss(const char* InName, int HP, int Dam);
	~Boss();
};


#pragma once
#include"Actor.h"
class Monster : public Actor
{
public:
	void Attack();
	void DamgeTaken(int Dam);
	virtual ~Monster() noexcept = default;
	virtual void ShowInfo() const override;
protected:
	Monster(const char* InName, int HP, int Dam, int Level);
};


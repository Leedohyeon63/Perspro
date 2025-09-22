#pragma once
#include"header.h"
#include"Battle.h"
class Actor : public Battle
{
public:
	inline const std::string GetName() const { return Name; }
	inline int GetHP() const { return ActorHP; }
	inline int GetATK() const { return Actordamge; }
	inline int Getorb() const { return healorb; }
	inline bool IsAlive() { return GetHP() > 0; }
	virtual void AppleyDamge(Battle* InTarget) override;
	virtual void Takedamge(int InDamge) override;
	virtual void Useskill(Actor* InTarget);
	Actor(const char* InName, int HP, int Dam);
	~Actor();
	inline void Sethealorb(int orb)
	{
		healorb = orb;
		if (healorb < 0)
		{
			healorb = 0;
		}
	}
	inline void SetDamge(int Dam)
	{
		Actordamge = Dam;
	}
protected:
	string Name;
	int ActorHP = 0, Actordamge = 0;
	int MaxHealth = 0, healorb = 0;

	inline void SetDamgetaken(int Dam)
	{
		ActorHP -= Dam;
	}
	inline void SetHealing(int heal)
	{
		ActorHP += heal;
	}

	inline void SetHealth(int InHealth)
	{
		if (InHealth > MaxHealth)
		{
			ActorHP = MaxHealth;
		}
		else
		{
			ActorHP = InHealth;
		}
	}
};


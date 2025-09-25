#pragma once
#include"header.h"
#include"Battle.h"
class Inventory;
class Actor : public Battle
{
public:
	inline const std::string GetName() const { return Name; }
	inline int GetHP() const { return ActorHP; }
	inline int GetATK() const { return Actordamge; }
	inline int Getorb() const { return healorb; }
	inline int GetGold() const { return Gold; }
	inline int GetLevel() const { return MonsterLevel; }
	inline bool IsAlive() { return GetHP() > 0; }
	virtual void AppleyDamge(Battle* InTarget) override;
	virtual void Takedamge(int InDamge) override;
	virtual void UseSkill(Actor* InTarget, Inventory* PInventory);
	virtual void UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern);
	virtual void ShowInfo() const;
	void ActorEffects();
	void ActorHealBlock(int turns);
	bool IsHealBlocked() const;
	bool CantHeal = false;
	int HealBlockedTurns = 0;
	Actor() : Name(""), ActorHP(0), Actordamge(0), MaxHealth(0), MonsterLevel(0){}
	Actor(const char* InName, int HP, int Dam,int Level);
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
		if (Actordamge < 0)
		{
			Actordamge = 1;
		}
	}
	inline void SetGold(int gold)
	{
		Gold = gold;
		if (Gold < 0)
		{
			Gold = 0;
		}
	}

protected:
	string Name;
	int ActorHP = 0, Actordamge = 0, MonsterLevel=0;
	int MaxHealth = 0, healorb = 0, Gold = 0;

	inline void SetDamgetaken(int Dam)
	{
		ActorHP -= Dam;
	}
	inline void SetHealing(int heal)
	{
		ActorHP += heal;
		printf("%d 만큼 회복 \n", Getorb());
		if (ActorHP > MaxHealth)
		{
			ActorHP = MaxHealth;
		}
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


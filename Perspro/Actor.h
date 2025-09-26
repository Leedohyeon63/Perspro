#pragma once
#include"header.h"
#include"Battle.h"
class Inventory;
class Actor : public Battle
{
public:
	inline const std::string GetName() const { return Name; }//객체 이름 리턴
	inline int GetHP() const { return ActorHP; }//객체 체력 리턴
	inline int GetATK() const { return Actordamge; }//객체 데미지 리턴
	inline int GetMaxHealth() const { return MaxHealth; }//객체의 최대체력을 리턴
	inline int Getorb() const { return healorb; }//객체(플레이어 고정)의 회복 오브를 리턴
	inline int GetGold() const { return Gold; }//객체(플레이어 고정)의 돈을 리턴
	inline int GetLevel() const { return MonsterLevel; }//객체의 회복 레벨을 리턴
	inline bool IsAlive() { return GetHP() > 0; }//객체가 살아있는지 검사
	virtual void AppleyDamge(Battle* InTarget) override;//데미지를 입히는 것을 처리하는 가상함수
	virtual void Takedamge(int InDamge) override;//데미지를 받는 것을 처리하는 가상함수
	virtual void UseSkill(Actor* InTarget, Inventory* PInventory);//몬스터의 스킬
	virtual void UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern);//보스패턴 (Nyleth클래스에 설명 있습니다..)
	virtual void ShowInfo() const;//객체정보
	void ActorEffects();//객체의 상태이상 관련 함수랑 변수들
	void ActorHealBlock(int turns);
	void ActorPoison(int turns, int DamagePerTurn);
	void ActorDamgeBuff(int turns, int BuffAmount);
	void ActorHealthRegen(int turns, int RegenPerTurn);
	bool IsHealBlocked() const;
	bool CantHeal = false;
	int HealBlockedTurns = 0;//여기까지
	Actor() : Name(""), ActorHP(0), Actordamge(0), MaxHealth(0), MonsterLevel(0){}
	Actor(const char* InName, int HP, int Dam,int Level);
	~Actor();
	inline void Sethealorb(int orb)//객체의 회복 오브를 설정

	{
		healorb = orb;
		if (healorb < 0)
		{
			healorb = 0;
		}
	}
	inline void SetDamge(int Dam)//객체의 데미지를 설정
	{
		Actordamge = Dam;
		if (Actordamge < 0)
		{
			Actordamge = 1;
		}
		printf("데미지가 %d로 증가.\n", GetATK());
	}
	inline void SetGold(int gold)//객체의 골드를 설정
	{
		Gold = gold;
		if (Gold < 0)
		{
			Gold = 0;
		}
	}
	inline void SetMaxHealth(int InHealth)//객체의 최대체력을 설정
	{
		MaxHealth = InHealth;
		printf("최대체력이 %d로 증가.\n", GetMaxHealth());
	}
protected:
	string Name;//객체 관련 변수들
	int ActorHP = 0, Actordamge = 0, MonsterLevel=0;
	int MaxHealth = 0, healorb = 0, Gold = 0;
	bool Poisoned = false;
	int PoisonTurns = 0;
	int PoisonDamagePerTurn = 0;
	bool DamageBuffed = false;
	int DamageBuffTurns = 0;
	int DamageBuffAmount = 0;
	bool Regenerating = false;
	int HealthRegenTurns = 0;
	int HealthRegenAmount = 0;
	inline void SetDamgetaken(int Dam)//객체가 데미지를 받을떄 나오는 함수
	{
		ActorHP -= Dam;
	}
	inline void SetHealing(int heal)//객체를 회복시킬 때 필요한 함수
	{
		ActorHP += heal;
		printf("%d 만큼 회복 \n", heal);
		if (ActorHP > MaxHealth)
		{
			ActorHP = MaxHealth;
		}
	}
	
	inline void SetHealth(int InHealth)//객체의 체력을 설정하는 함수
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


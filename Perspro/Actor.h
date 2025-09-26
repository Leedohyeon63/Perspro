#pragma once
#include"header.h"
#include"Battle.h"
class Inventory;
class Actor : public Battle
{
public:
	inline const std::string GetName() const { return Name; }//��ü �̸� ����
	inline int GetHP() const { return ActorHP; }//��ü ü�� ����
	inline int GetATK() const { return Actordamge; }//��ü ������ ����
	inline int GetMaxHealth() const { return MaxHealth; }//��ü�� �ִ�ü���� ����
	inline int Getorb() const { return healorb; }//��ü(�÷��̾� ����)�� ȸ�� ���긦 ����
	inline int GetGold() const { return Gold; }//��ü(�÷��̾� ����)�� ���� ����
	inline int GetLevel() const { return MonsterLevel; }//��ü�� ȸ�� ������ ����
	inline bool IsAlive() { return GetHP() > 0; }//��ü�� ����ִ��� �˻�
	virtual void AppleyDamge(Battle* InTarget) override;//�������� ������ ���� ó���ϴ� �����Լ�
	virtual void Takedamge(int InDamge) override;//�������� �޴� ���� ó���ϴ� �����Լ�
	virtual void UseSkill(Actor* InTarget, Inventory* PInventory);//������ ��ų
	virtual void UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern);//�������� (NylethŬ������ ���� �ֽ��ϴ�..)
	virtual void ShowInfo() const;//��ü����
	void ActorEffects();//��ü�� �����̻� ���� �Լ��� ������
	void ActorHealBlock(int turns);
	void ActorPoison(int turns, int DamagePerTurn);
	void ActorDamgeBuff(int turns, int BuffAmount);
	void ActorHealthRegen(int turns, int RegenPerTurn);
	bool IsHealBlocked() const;
	bool CantHeal = false;
	int HealBlockedTurns = 0;//�������
	Actor() : Name(""), ActorHP(0), Actordamge(0), MaxHealth(0), MonsterLevel(0){}
	Actor(const char* InName, int HP, int Dam,int Level);
	~Actor();
	inline void Sethealorb(int orb)//��ü�� ȸ�� ���긦 ����

	{
		healorb = orb;
		if (healorb < 0)
		{
			healorb = 0;
		}
	}
	inline void SetDamge(int Dam)//��ü�� �������� ����
	{
		Actordamge = Dam;
		if (Actordamge < 0)
		{
			Actordamge = 1;
		}
		printf("�������� %d�� ����.\n", GetATK());
	}
	inline void SetGold(int gold)//��ü�� ��带 ����
	{
		Gold = gold;
		if (Gold < 0)
		{
			Gold = 0;
		}
	}
	inline void SetMaxHealth(int InHealth)//��ü�� �ִ�ü���� ����
	{
		MaxHealth = InHealth;
		printf("�ִ�ü���� %d�� ����.\n", GetMaxHealth());
	}
protected:
	string Name;//��ü ���� ������
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
	inline void SetDamgetaken(int Dam)//��ü�� �������� ������ ������ �Լ�
	{
		ActorHP -= Dam;
	}
	inline void SetHealing(int heal)//��ü�� ȸ����ų �� �ʿ��� �Լ�
	{
		ActorHP += heal;
		printf("%d ��ŭ ȸ�� \n", heal);
		if (ActorHP > MaxHealth)
		{
			ActorHP = MaxHealth;
		}
	}
	
	inline void SetHealth(int InHealth)//��ü�� ü���� �����ϴ� �Լ�
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


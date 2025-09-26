#include "Nyleth.h"

void Nyleth::UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern)
{
	int Pattern = InPattern % 3; //InPattern = MonsterTurnCounter ���� ������ �ܼ� �ݺ��̶�  ���� ������ŭ ������
	switch (Pattern)
	{
	case 1:
		BladeSurge(InTarget, PInventory);
		break;
	case 2:
		ThrowSeed(InTarget, PInventory);
		break;
	case 0://������ ��ų�� case0
		Bloom(InTarget, PInventory);
		break;
	default:
		break;
	}
}

void Nyleth::BladeSurge(Actor* InTarget, Inventory* PInventory)
{
	printf("���̷����� Į���� �ֵθ��� �ֽ��ϴ�.\n");
	if (PInventory->IsEquip("������"))//Ư�� �������� �����ϰ� ������ ���� ���� �������� ��Ʈ���� �����Ѵ�.
	{
		printf("���з� �������� ���ҽ��ϴ�..\n");
		BladeHit = 1;
	}
	for (int i = 0; i < BladeHit; i++)
	{
		InTarget->Takedamge(BladeDamge);
	}
}

void Nyleth::ThrowSeed(Actor* InTarget, Inventory* PInventory)
{
	printf("���̷����� ������ �߻��մϴ�.\n");
	if (PInventory->IsEquip("�ɰ�����"))
	{
		printf("���������� ���ҽ��ϴ�..\n");
		SeedHit = 2;
	}
	for (int i = 0; i < SeedHit; i++)
	{
		InTarget->Takedamge(SeedDamge);
	}
}

void Nyleth::Bloom(Actor* InTarget, Inventory* PInventory)
{
	printf("���̷����� ������ �����մϴ�.\n");
	if (PInventory->IsEquip("������"))
	{
		printf("���� ������ ����մϴ�..\n");
	}
	else
	{
		InTarget->ActorPoison(BloomPoisonHit, BloomPoison);
	}
	InTarget->Takedamge(BloomDamge);
}
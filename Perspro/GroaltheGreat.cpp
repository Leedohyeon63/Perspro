#include "GroaltheGreat.h"

void GroaltheGreat::UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern)
{
	int Pattern = InPattern % 4;
	switch (Pattern)
	{
	case 1:
		Rush(InTarget, PInventory);
		break;
	case 2:
		Inhale(InTarget, PInventory);
		break;
	case 3:
		MaggotsTale(InTarget, PInventory);
		break;
	case 0:
		SoulThrow(InTarget, PInventory);
		break;
	default:
		break;
	}
}

void GroaltheGreat::Rush(Actor* InTarget, Inventory* PInventory)
{
	printf("�׷��� �����մϴ�.\n");
	if (PInventory->IsEquip("���̱���"))
	{
		printf("������ ������ ���մϴ�.\n");
		RushDamge = 1;
	}
	InTarget->Takedamge(RushDamge);
}

void GroaltheGreat::Inhale(Actor* InTarget, Inventory* PInventory)
{
	printf("�׷��� �÷��̾ ���Ƶ��Դϴ�.\n");
	if (PInventory->IsEquip("���̱���"))
	{
		printf("������ ���Խ��ϴ�.\n");
		InhaleHit = 1;
	}
	for (size_t i = 0; i < InhaleHit; i++)
	{
		InTarget->Takedamge(InhaleDamge);
	}
}

void GroaltheGreat::MaggotsTale(Actor* InTarget, Inventory* PInventory)
{
	printf("�׷��� ������ ��ġ�� �߻��մϴ�.\n");
	if (PInventory->IsEquip("������ȭȯ"))
	{
		printf("�����⸦ ��� ƨ�ܳ��ϴ�.\n");
	}
	else
	{
		InTarget->ActorHealBlock(Maggotstime);
	}
	InTarget->Takedamge(MaggotsTaleDamge);
}

void GroaltheGreat::SoulThrow(Actor* InTarget, Inventory* PInventory)
{
	if (IsBerserk() && BerserkeTrigger && !(PInventory->IsEquip("������ȭȯ")))
	{
		printf("�׷��� �г��մϴ�...\n");
		SoulThrowDamge *= 3;
		SoulThrowHit *= 2;
		BerserkeTrigger = false;
	}
	printf("�׷��� ��ȥ�� �߻��մϴ�.\n");
	for (size_t i = 0; i < SoulThrowHit; i++)
	{
		InTarget->Takedamge(SoulThrowDamge);
	}
}

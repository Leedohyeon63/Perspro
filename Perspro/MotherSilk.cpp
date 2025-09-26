#include "MotherSilk.h"

void MotherSilk::Takedamge(int Dam)
{
	Monster::Takedamge(Dam);
	IsDamTaken = true;
}

void MotherSilk::UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern)
{
	int Pattern = InPattern % 5;
	switch (Pattern)
	{
	case 1:
		Silkspear(InTarget, PInventory);
		break;
	case 2:
		ThreadStorm(InTarget, PInventory);
		break;
	case 3:
		CrossStitch(InTarget, PInventory);
		break;
	case 4:
		RuneRage(InTarget, PInventory);
		break;
	case 0:
		PaleNails(InTarget, PInventory);
		break;
	default:
		break;
	}
	IsDamTaken = false;
}

void MotherSilk::Silkspear(Actor* InTarget, Inventory* PInventory)
{
	printf("��ũ�� â�� �����ϴ�..\n");
	InTarget->Takedamge(SilkspearDamge);
}

void MotherSilk::ThreadStorm(Actor* InTarget, Inventory* PInventory)
{
	printf("��ũ�� ������ ��ǳ�� �Ͼ�ϴ�..\n");
	if (PInventory->IsEquip("���̱���")&&!IsDamTaken)
	{
		printf("������ ���Խ��ϴ�.\n");
		ThreadStormHit = 2;
	}
	for (size_t i = 0; i < ThreadStormHit; i++)
	{
		InTarget->Takedamge(ThreadStormDamge);
	}
}

void MotherSilk::CrossStitch(Actor* InTarget, Inventory* PInventory)
{
	if (IsDamTaken)
	{
		printf("��ũ�� ������ �и��մϴ�..\n");
		InTarget->Takedamge(CrossStitchDamge);
	}
}

void MotherSilk::RuneRage(Actor* InTarget, Inventory* PInventory)
{
	RuneRageHit = rand() % 6 + 1;
	printf("��ũ�� ������ ������ �Ͼ�ϴ�..\n");
	for (size_t i = 0; i < RuneRageHit; i++)
	{
		InTarget->Takedamge(RuneRageDamge);
	}
}

void MotherSilk::PaleNails(Actor* InTarget, Inventory* PInventory)
{
	if (PaleNailsCount==0)
	{
		printf("��ũ�� �Ŵ��� �ٴ��� �����ϴ�..\n");
		for (size_t i = 0; i < PaleNailsHit; i++)
		{
			InTarget->Takedamge(PaleNailsDamge);
		}
		PaleNailsCount = 3;
	}
	else
	{
		printf("��ũ�� �Ƿ� ���� ����� �ֽ��ϴ�..\n");
		printf("===================================\n");
		PaleNailsCount--;

	}
	
}

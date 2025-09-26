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
	printf("실크가 창을 날립니다..\n");
	InTarget->Takedamge(SilkspearDamge);
}

void MotherSilk::ThreadStorm(Actor* InTarget, Inventory* PInventory)
{
	printf("실크의 주위에 폭풍이 일어납니다..\n");
	if (PInventory->IsEquip("페이깃털")&&!IsDamTaken)
	{
		printf("빠르게 나왔습니다.\n");
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
		printf("실크가 공격을 패링합니다..\n");
		InTarget->Takedamge(CrossStitchDamge);
	}
}

void MotherSilk::RuneRage(Actor* InTarget, Inventory* PInventory)
{
	RuneRageHit = rand() % 6 + 1;
	printf("실크의 주위에 폭발이 일어납니다..\n");
	for (size_t i = 0; i < RuneRageHit; i++)
	{
		InTarget->Takedamge(RuneRageDamge);
	}
}

void MotherSilk::PaleNails(Actor* InTarget, Inventory* PInventory)
{
	if (PaleNailsCount==0)
	{
		printf("실크가 거대한 바늘을 날립니다..\n");
		for (size_t i = 0; i < PaleNailsHit; i++)
		{
			InTarget->Takedamge(PaleNailsDamge);
		}
		PaleNailsCount = 3;
	}
	else
	{
		printf("실크가 실로 무언갈 만들고 있습니다..\n");
		printf("===================================\n");
		PaleNailsCount--;

	}
	
}

#include "Nyleth.h"

void Nyleth::UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern)
{
	int Pattern = InPattern % 3;
	switch (Pattern)
	{
	case 1:
		BladeSurge(InTarget, PInventory);
		break;
	case 2:
		ThrowSeed(InTarget, PInventory);
		break;
	case 0:
		Bloom(InTarget, PInventory);
		break;
	default:
		break;
	}
}

void Nyleth::BladeSurge(Actor* InTarget, Inventory* PInventory)
{
	printf("나이레스가 칼날을 휘두르고 있습니다.\n");
	if (PInventory->FindItem("뼈 방패"))
	{
		printf("방패로 데미지를 막았습니다..\n");
		BladeHit = 1;
	}
	for (int i = 0; i < BladeHit; i++)
	{
		InTarget->Takedamge(BladeDamge);
	}
}

void Nyleth::ThrowSeed(Actor* InTarget, Inventory* PInventory)
{
	printf("나이레스가 씨앗을 발사합니다.\n");
	if (PInventory->FindItem("꽃 가림막"))
	{
		printf("가림막으로 막았습니다..\n");
		SeedHit = 2;
	}
	for (int i = 0; i < SeedHit; i++)
	{
		InTarget->Takedamge(SeedDamge);
	}
}

void Nyleth::Bloom(Actor* InTarget, Inventory* PInventory)
{
	printf("나이레스가 폭발을 시전합니다.\n");
	InTarget->ActorPoison(BloomPoisonHit, BloomPoison);
	InTarget->Takedamge(BloomDamge);
}
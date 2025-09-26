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
	printf("그롤이 돌진합니다.\n");
	if (PInventory->IsEquip("페이깃털"))
	{
		printf("빠르게 돌진을 피합니다.\n");
		RushDamge = 1;
	}
	InTarget->Takedamge(RushDamge);
}

void GroaltheGreat::Inhale(Actor* InTarget, Inventory* PInventory)
{
	printf("그롤이 플레이어를 빨아들입니다.\n");
	if (PInventory->IsEquip("페이깃털"))
	{
		printf("빠르게 나왔습니다.\n");
		InhaleHit = 1;
	}
	for (size_t i = 0; i < InhaleHit; i++)
	{
		InTarget->Takedamge(InhaleDamge);
	}
}

void GroaltheGreat::MaggotsTale(Actor* InTarget, Inventory* PInventory)
{
	printf("그롤이 구더기 뭉치를 발사합니다.\n");
	if (PInventory->IsEquip("순수의화환"))
	{
		printf("구더기를 모두 튕겨냅니다.\n");
	}
	else
	{
		InTarget->ActorHealBlock(Maggotstime);
	}
	InTarget->Takedamge(MaggotsTaleDamge);
}

void GroaltheGreat::SoulThrow(Actor* InTarget, Inventory* PInventory)
{
	if (IsBerserk() && BerserkeTrigger && !(PInventory->IsEquip("순수의화환")))
	{
		printf("그롤이 분노합니다...\n");
		SoulThrowDamge *= 3;
		SoulThrowHit *= 2;
		BerserkeTrigger = false;
	}
	printf("그롤이 영혼을 발사합니다.\n");
	for (size_t i = 0; i < SoulThrowHit; i++)
	{
		InTarget->Takedamge(SoulThrowDamge);
	}
}

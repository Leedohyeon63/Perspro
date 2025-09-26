#include "Trobbio.h"
#include "Nyleth.h"

void Trobbio::UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern)
{
	int Pattern = InPattern % 4;
	switch (Pattern)
	{
	case 1:
		Firebomb(InTarget, PInventory);
		break;
	case 2:
		Tornado(InTarget, PInventory);
		break;
	case 3:
		FireWork(InTarget, PInventory);
		break;
	case 0:
		FirecrackerAttack(InTarget, PInventory);
		break;
	default:
		break;
	}
}

void Trobbio::Firebomb(Actor* InTarget, Inventory* PInventory)
{
	printf("토르비오가 폭탄을 던집니다.\n");
	if (PInventory->IsEquip("용암의종"))
	{
		printf("용암 종이 피해를 감소시킵니다.\n");
		bombDamge = 10;
	}
	InTarget->Takedamge(bombDamge);
}

void Trobbio::Tornado(Actor* InTarget, Inventory* PInventory)
{
	printf("토르비오가 소용돌이가 되어 날아옵니다.\n");

	for (int i = 0; i < TornadoHit; i++)
	{
		InTarget->Takedamge(TornadoDamge);
	}
}

void Trobbio::FireWork(Actor* InTarget, Inventory* PInventory)
{
	printf("토르비오가 불꽃을 날립니다.\n");
	if (PInventory->IsEquip("용암의종"))
	{
		printf("용암 종이 피해를 감소시킵니다.\n");
		FireWorkDamge = 10;
	}
	InTarget->Takedamge(FireWorkDamge);

}

void Trobbio::FirecrackerAttack(Actor* InTarget, Inventory* PInventory)
{
	if (FirecrackerCount == 4)
	{
		printf("토르비오가 불꽃놀이를 시작합니다.\n");
		if (PInventory->IsEquip("용암의종"))
		{
			printf("용암 종이 피해를 감소시킵니다.\n");
			FirecrackerDamge = 30;
		}
		InTarget->Takedamge(FirecrackerDamge);
		FirecrackerCount = 0;
	}
	else
	{
		printf("토르비오가 무언가를 준비합니다..\n");
		printf("==============================\n");
		FirecrackerCount++;
	}
}

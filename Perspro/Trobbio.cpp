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
	printf("�丣����� ��ź�� �����ϴ�.\n");
	if (PInventory->IsEquip("�������"))
	{
		printf("��� ���� ���ظ� ���ҽ�ŵ�ϴ�.\n");
		bombDamge = 10;
	}
	InTarget->Takedamge(bombDamge);
}

void Trobbio::Tornado(Actor* InTarget, Inventory* PInventory)
{
	printf("�丣����� �ҿ뵹�̰� �Ǿ� ���ƿɴϴ�.\n");

	for (int i = 0; i < TornadoHit; i++)
	{
		InTarget->Takedamge(TornadoDamge);
	}
}

void Trobbio::FireWork(Actor* InTarget, Inventory* PInventory)
{
	printf("�丣����� �Ҳ��� �����ϴ�.\n");
	if (PInventory->IsEquip("�������"))
	{
		printf("��� ���� ���ظ� ���ҽ�ŵ�ϴ�.\n");
		FireWorkDamge = 10;
	}
	InTarget->Takedamge(FireWorkDamge);

}

void Trobbio::FirecrackerAttack(Actor* InTarget, Inventory* PInventory)
{
	if (FirecrackerCount == 4)
	{
		printf("�丣����� �Ҳɳ��̸� �����մϴ�.\n");
		if (PInventory->IsEquip("�������"))
		{
			printf("��� ���� ���ظ� ���ҽ�ŵ�ϴ�.\n");
			FirecrackerDamge = 30;
		}
		InTarget->Takedamge(FirecrackerDamge);
		FirecrackerCount = 0;
	}
	else
	{
		printf("�丣����� ���𰡸� �غ��մϴ�..\n");
		printf("==============================\n");
		FirecrackerCount++;
	}
}

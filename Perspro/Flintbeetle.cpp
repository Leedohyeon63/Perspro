#include "Flintbeetle.h"

void Flintbeetle::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	FlintAttack(InTarget, PInventory);
}

void Flintbeetle::FlintAttack(Actor* InTarget, Inventory* PInventory)
{
	printf("���� �Ӹ��� �ν˵��� �����ϴ�..\n");
	if (PInventory->IsEquip("�������"))
	{
		printf("��� ���� ���ظ� ���ҽ�ŵ�ϴ�.\n");
		flintDamge = 10;
	}
	InTarget->Takedamge(flintDamge);
}

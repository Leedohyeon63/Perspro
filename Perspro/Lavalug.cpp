#include "Lavalug.h"

void Lavalug::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	LavaAttack(InTarget, PInventory);
}

void Lavalug::LavaAttack(Actor* InTarget, Inventory* PInventory)
{
	printf("���Ͱ� ����� �߻��մϴ�.\n");
	if (PInventory->IsEquip("�������"))
	{
		printf("��� ���� ���ظ� ���ҽ�ŵ�ϴ�.\n");
		LavaDamge = 5;
	}
	InTarget->Takedamge(LavaDamge);
}

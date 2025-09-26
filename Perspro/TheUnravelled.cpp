#include "TheUnravelled.h"
void TheUnravelled::Takedamge(int Dam)
{
	Monster::Takedamge(Dam);
	IsDamTaken = true;
}

void TheUnravelled::UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern)
{
	if (IsRage)
	{
		if (PInventory != nullptr && !PInventory->FindListItem("ȭ���� ����"))
		{
			printf("�Ҳ��� ���� �����ϴ� Ǯ���� ���� ü���� �þ�ϴ�..\n");
			SetMaxHealth(GetMaxHealth() * 2);
			SetHealth(GetHP() * 2);
		}
		if (PInventory != nullptr && !PInventory->FindListItem("���� ����"))
		{
			printf("�ڿ��� ���� �����ϴ� Ǯ���� ���� ���ݷ��� �������ϴ�..\n");
			SetDamge(GetATK() * 3);
		}
		if (PInventory != nullptr && !PInventory->FindListItem("���ܿ� ����"))
		{
			printf("��ȥ�� ���� �����ϴ� Ǯ���� ���� ����� �������� ũ�� �����մϴ�..\n");
			UnravelledRushDamge = 140;
			SpearThrowDamge = 170;
			JudgeDamge = 240;
			VoltvesselsDamge = 70;
			VoltvesselsHit = 6;
			RosaryShootDamge = 100;
			LightBeamDamge = 300;
			PurgatoriumDamge = 400;
		}
		if (PInventory != nullptr && !PInventory->FindListItem("�Ƿ� ���� ����"))
		{
			printf("��ũ�� ���� �����ϴ� ");
		}
		IsRage = false;
	}
	int Pattern = InPattern % 4;
	if (IsBerserk()|| (PInventory != nullptr && !PInventory->FindListItem("�Ƿ� ���� ����")))
	{
		printf("Ǯ���� �ڰ� �г� �����Դϴ�..\n");
		Pattern = InPattern % 7;
	}
	switch (Pattern)
	{
	case 1:
		UnravelledRush(InTarget, PInventory);
		break;
	case 2:
		SpearThrow(InTarget, PInventory);
		break;
	case 3:
		Voltvessels(InTarget, PInventory);
		break;
	case 4:
		RosaryShoot(InTarget, PInventory);
		break;
	case 5:
		Judge(InTarget, PInventory);
		break;
	case 6:
		Purgatorium(InTarget, PInventory);
		break;
	case 0:
		LightBeam(InTarget, PInventory);
		break;
	default:
		break;
	}
	IsDamTaken = false;
}

void TheUnravelled::UnravelledRush(Actor* InTarget, Inventory* PInventory)
{
	printf("Ǯ���� �ڰ� ���� �� ���� �ӵ��� �����մϴ�..\n");
	InTarget->Takedamge(UnravelledRushDamge);
}

void TheUnravelled::SpearThrow(Actor* InTarget, Inventory* PInventory)
{
	printf("�Ӹ� ������ â�� �������ϴ�..\n");
	InTarget->Takedamge(SpearThrowDamge);
}

void TheUnravelled::Judge(Actor* InTarget, Inventory* PInventory)
{
	printf("Ǯ���� �ڰ� ������ �����ϴ�..\n");
	if (IsDamTaken)
	{
		printf("����..\n");
		JudgeDamge *= 2;

	}
	else
	{
		printf("����..\n");
		JudgeDamge /= 2;

	}
	InTarget->Takedamge(JudgeDamge);
}

void TheUnravelled::Voltvessels(Actor* InTarget, Inventory* PInventory)
{
	printf("�Ŵ��� ������ ���ƿɴϴ�..\n");
	for (size_t i = 0; i < VoltvesselsHit; i++)
	{
		InTarget->Takedamge(VoltvesselsDamge);
	}
}

void TheUnravelled::RosaryShoot(Actor* InTarget, Inventory* PInventory)
{
	if (InTarget->Getorb() > 0)
	{
		printf("Ǯ���� �ڰ� ����� ���긦 �Ҹ��ŵ�ϴ�..\n");
		InTarget->Takedamge(RosaryShootDamge);
		InTarget->Sethealorb(InTarget->Getorb()- RosaryShootDamge);
	}
	else
	{
		printf("���갡 ���� ü���� ���İ��ϴ�..\n");
		InTarget->Takedamge(RosaryShootDamge*2);
		printf("Ǯ���� �ڰ� ȸ���մϴ�..\n");
		SetHealing(RosaryShootDamge * 10);
	}
}

void TheUnravelled::LightBeam(Actor* InTarget, Inventory* PInventory)
{
	if (LightBeamcount == 0)
	{
		printf("�Ŵ��� ������ �߻��մϴ�..\n");
		InTarget->Takedamge(LightBeamDamge);
		LightBeamcount = MaxCount;
	}
	else
	{
		printf("Ǯ���� �ڰ� �� �ð� �Ŵ��� ���� ������ �ֽ��ϴ�..\n");
		LightBeamcount--;
	}
}

void TheUnravelled::Purgatorium(Actor* InTarget, Inventory* PInventory)
{
	printf("Ǯ���� �ڰ� ������ �������ϴ�..\n");
	if (PInventory->IsEquip("�����Ѳ�"))
	{
		printf("���� ���⸦ ��� ����մϴ�..\n");
		PurgatoriumDamge = 0;
	}
	else if (PInventory->IsEquip("�������"))
	{
		printf("��� ���� ���ظ� ���ҽ�ŵ�ϴ�.\n");
		PurgatoriumDamge = 100;
	}
	InTarget->Takedamge(PurgatoriumDamge);
}

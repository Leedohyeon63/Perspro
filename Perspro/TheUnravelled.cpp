#include "TheUnravelled.h"
void TheUnravelled::Takedamge(int Dam)
{
	Monster::Takedamge(Dam);
	IsDamTaken = true;
}

void TheUnravelled::UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern)
{
	int Pattern = InPattern % 4;
	if (IsBerserk())
	{
		printf("풀려난 자가 분노 상태입니다.");
		int Pattern = InPattern % 7;
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
	printf("풀려난 자가 피할 수 없는 속도로 돌진합니다..\n");
	InTarget->Takedamge(UnravelledRushDamge);
}

void TheUnravelled::SpearThrow(Actor* InTarget, Inventory* PInventory)
{
	printf("머리 위에서 창이 떨어집니다..\n");
	InTarget->Takedamge(SpearThrowDamge);
}

void TheUnravelled::Judge(Actor* InTarget, Inventory* PInventory)
{
	printf("풀려난 자가 심판을 내립니다..\n");
	if (IsDamTaken)
	{
		printf("유죄..\n");
		JudgeDamge *= 2;

	}
	else
	{
		printf("무죄..\n");
		JudgeDamge /= 2;

	}
	InTarget->Takedamge(SpearThrowDamge);
}

void TheUnravelled::Voltvessels(Actor* InTarget, Inventory* PInventory)
{
	printf("거대한 벼락이 날아옵니다..\n");
	for (size_t i = 0; i < VoltvesselsHit; i++)
	{
		InTarget->Takedamge(VoltvesselsDamge);
	}
}

void TheUnravelled::RosaryShoot(Actor* InTarget, Inventory* PInventory)
{
	if (InTarget->Getorb() > 0)
	{
		printf("풀려난 자가 당신의 오브를 소멸시킵니다..\n");
		InTarget->Takedamge(RosaryShootDamge);
		InTarget->Sethealorb(InTarget->Getorb()- RosaryShootDamge);
	}
	else
	{
		printf("오브가 없어 체력을 훔쳐갑니다..\n");
		InTarget->Takedamge(RosaryShootDamge*2);
		printf("풀려난 자가 회복합니다..\n");
		SetHealing(RosaryShootDamge * 10);
	}
}

void TheUnravelled::LightBeam(Actor* InTarget, Inventory* PInventory)
{
	if (LightBeamcount == 0)
	{
		printf("거대한 광선을 발사합니다..\n");
		InTarget->Takedamge(LightBeamDamge);
		LightBeamcount = MaxCount;
	}
	else
	{
		printf("풀려난 자가 긴 시간 거대한 빛을 모으고 있습니다..\n");
		LightBeamcount--;
	}
}

void TheUnravelled::Purgatorium(Actor* InTarget, Inventory* PInventory)
{
	printf("풀려난 자가 연옥을 열었습니다..\n");
	if (PInventory->FindItem("연약한 꽃"))
	{
		printf("꽃이 열기를 모두 흡수합니다..\n");
		PurgatoriumDamge = 0;
	}
	else if (PInventory->FindItem("용암 종"))
	{
		printf("용암 종이 피해를 감소시킵니다.\n");
		PurgatoriumDamge = 100;
	}
	InTarget->Takedamge(PurgatoriumDamge);
}

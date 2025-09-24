#include "Actor.h"
void Actor::AppleyDamge(Battle* InTarget)
{
	int AttackPower = GetATK();
	InTarget->Takedamge(AttackPower);
}
void Actor::Takedamge(int InDamge)
{
	SetHealth(GetHP() - InDamge);

	printf("%s�� %d�� ���ظ� �Ծ����ϴ�.\n", Name.c_str(), InDamge);
	printf("(%d/%d)\n", GetHP(), MaxHealth);

	if (!IsAlive())
	{
		printf("%s�� �׾����ϴ�.\n", Name.c_str());
	}
}
void Actor::Useskill(Actor* InTarget)
{
	printf("���Ͱ� ��ų�� ����մϴ�\n");
}

void Actor::ShowInfo() const
{
	printf("�̸� : %s\n", Name.c_str());
	printf("ü�� : %d / %d\n", ActorHP, MaxHealth);
	printf("���ݷ� : %d\n", Actordamge);
	printf("���� : %d\n", MonsterLevel);
}


Actor::Actor(const char* InName, int HP, int Dam, int Level)
	:Name(InName), ActorHP(HP), Actordamge(Dam), MaxHealth(HP), MonsterLevel(Level)
{

}
Actor::~Actor() {

}
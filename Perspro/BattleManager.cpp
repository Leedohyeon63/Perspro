#include "BattleManager.h"
#include<iostream>
//���� ���� �Լ��� �����ϴ� Ŭ����
BattleResult BattleManager::MonsterBattle(Player* player, Actor* monster, Inventory* inventory)
{//�Ϲ� ���Ϳ��� �������θ� ���ϰ� ���� ����� �����ϴ� �޼ҵ�
	auto Choise = 0;
	printf("1. �ο� 2. ���� : ");
	cin >> Choise;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "�߸��� �Է��Դϴ�. �г�Ƽ.\n";
		player->PlayerDmagetaken(30);
	}
	else {
		if (Choise == 1 && monster->GetLevel())
		{
			if (MonsterFight(player, monster, inventory))//�������� ������ MonsterFight
			{
				return BattleResult::WIN;
			}
			else
			{
				return BattleResult::LOSE;
			}

		}
		else if (Choise == 2)
		{
			player->PlayerDmagetaken(10);
			player->Sethealorb(player->Getorb()/3);
			player->SetGold(player->GetGold()/2);//������ �г�Ƽ�� ���� 66��, �� 50�� ������
			return BattleResult::RUN;
		}
		else
		{
			printf("�߸��� �Է�\n");
			return BattleResult::ERROR;
		}
	}
	return BattleResult::ERROR;
}

BattleResult BattleManager::BossBattle(Player* player, Actor* boss, Inventory* inventory)
{//���� ���Ϳ��� �������θ� ���ϰ� ���� ����� �����ϴ� �޼ҵ�
	auto Choise = 0;
	printf("������ �����Ͻðڽ��ϱ�? (1. ��/2. �ƴϿ�) : ");
	cin >> Choise;
	if (cin.fail()) 
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "�߸��� �Է��Դϴ�.\n";
	}
	else {
		if (Choise == 1)
		{
			if (BossFight(player, boss, inventory))//������ ���� �����ϰ� �������� ������ �ٸ� �޼ҵ忡�� ��
			{
				return BattleResult::WIN;
			}
			else
			{
				return BattleResult::LOSE;
			}
		}
		else if (Choise == 2)
		{
			return BattleResult::RUN;
		}
	}

		return BattleResult::ERROR;
}


bool BattleManager::BossFight(Player* player, Actor* boss, Inventory* inventory)
{//���� ���Ϳ� �����ϴ� �޼ҵ�
	MonsterTurnCounter = 0;//��ų ����� ���� ���� ���� ǥ�����ִ� �޼ҵ�, ������ �������� ������ ������ �޶� 0���� �ʱ�ȭ
	int GuardCoolDown = 0;//���� ��Ÿ�� 0�϶� �غ� �Ϸ�
	system("cls");
    while (player->IsAlive() && boss->IsAlive())
    {
		auto Choise = 0;
		MonsterTurnCounter++;
		printf("1. ���� / 2. ȸ��(���� %d ��) / 3. ������ ��� ",player->Getorb()); 
		if (GuardCoolDown == 0) 
		{
			printf("4. ����(����) : ");
		}
		else
		{ 
			printf("3. ����(�Ұ���, %d�� ����) : ", GuardCoolDown);//����� 5���� ��Ÿ���� ������ ������ ���� ������ �׳� �ѱ�� ����
		}
		cin >> Choise;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�߸��� �Է��Դϴ�.\n";
			if (MonsterTurnCounter>1)
			{
				MonsterTurnCounter--;
			}
			continue;
		}
		else {
			if (Choise == 1)
			{
				player->ActorEffects();
				printf("\n�÷��̾� ����\n");
				boss->Takedamge(player->GetATK());
				if (!boss->IsAlive())
				{
					return true;
				}
				printf("\n���� ����\n");
				boss->UsePattern(player, inventory, MonsterTurnCounter);
				if (!player->IsAlive())
				{
					return false;
				}
				if (GuardCoolDown!=0)
				{
					GuardCoolDown--;
				}
			}
			else if (Choise == 2)
			{
				if (!(player->IsHealBlocked()))
				{
					player->PlayerHealing(player->Getorb());
					player->Sethealorb(0);
				}
				else
				{
					printf("���� ȸ�� �Ұ���");

				}
				player->Takedamge(boss->GetATK());

			}
			else if (Choise == 3)
			{
				inventory->BattleUse(*player);
				player->Takedamge(boss->GetATK());
			}
			else if (Choise == 4)
			{
				printf("������ ������ ����߽��ϴ�.\n");
				GuardCoolDown = 5;
				continue;
			}
		}
    }
	return false;
}


bool BattleManager::MonsterFight(Player* player, Actor* monster, Inventory* inventory)
{//�Ϲ� ���Ϳ� �����ϴ� �޼ҵ�
    system("cls");
    while (player->IsAlive() && monster->IsAlive())
    {
        printf("�÷��̾� ����\n");
		player->ActorEffects();
        monster->Takedamge(player->GetATK());
        if (!monster->IsAlive())
        {
            return true;
        }

        printf("���� ����\n");
		monster->ActorEffects();
        MonsterTurnCounter++; //��ų ����� ���� ���� ���� ǥ�����ִ� �޼ҵ�
        if (monster->GetLevel() > 3)//���� ������ ���� ��ų ������ �ٸ� 3�̻��� �ι�° ���ݸ��� �ѹ�,
        {							//2�� �����Ҷ� �ѹ�, 1�� �⺻ ���ݸ� ���� 
            if (MonsterTurnCounter % 2 == 0)
            {
                printf("���� ��ų ���\n");
                monster->UseSkill(player, inventory);
            }
            else
            {
                player->Takedamge(monster->GetATK());
            }
        }

        else if (monster->GetLevel() == 3 && !SkillUsed)
        {
            printf("���� ��ų ���\n");
            monster->UseSkill(player, inventory);
            SkillUsed = true; 
        }
        else
        {
            player->Takedamge(monster->GetATK());
        }

        if (!player->IsAlive())
        {
            return false; 
        }

    }
    return player->IsAlive();
}



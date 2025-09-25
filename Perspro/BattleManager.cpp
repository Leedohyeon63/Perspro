#include "BattleManager.h"
#include<iostream>
BattleResult BattleManager::MonsterBattle(Player* player, Actor* monster, Inventory* inventory)
{
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
			if (MonsterFight(player, monster, inventory))
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
			player->SetGold(player->GetGold()/2);
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
{
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
			if (BossFight(player, boss, inventory))
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
{
	MonsterTurnCounter = 0;
	int GuardCoolDown = 0;
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
			printf("3. ����(�Ұ���, %d�� ����) : ", GuardCoolDown);
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
				inven.WhatUse(*player);
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
{
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
        MonsterTurnCounter++; 
        if (monster->GetLevel() > 3)
        {
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



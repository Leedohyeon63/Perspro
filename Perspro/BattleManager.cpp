#include "BattleManager.h"
#include<iostream>
BattleResult BattleManager::MonsterBattle(Player* player, Actor* monster, Inventory* inventory)
{
	auto Choise = 0;
	printf("1. 싸움 2. 도망 : ");
	cin >> Choise;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "잘못된 입력입니다. 패널티.\n";
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
			printf("잘못된 입력\n");
			return BattleResult::ERROR;
		}
	}
	return BattleResult::ERROR;
}

BattleResult BattleManager::BossBattle(Player* player, Actor* boss, Inventory* inventory)
{
	auto Choise = 0;
	printf("보스에 도전하시겠습니까? (1. 네/2. 아니오) : ");
	cin >> Choise;
	if (cin.fail()) 
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "잘못된 입력입니다.\n";
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
		printf("1. 공격 / 2. 회복(오브 %d 개) / 3. 아이템 사용 ",player->Getorb()); 
		if (GuardCoolDown == 0) 
		{
			printf("4. 가드(가능) : ");
		}
		else
		{ 
			printf("3. 가드(불가능, %d턴 남음) : ", GuardCoolDown);
		}
		cin >> Choise;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "잘못된 입력입니다.\n";
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
				printf("\n플레이어 공격\n");
				boss->Takedamge(player->GetATK());
				if (!boss->IsAlive())
				{
					return true;
				}
				printf("\n보스 공격\n");
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
					printf("현재 회복 불가능");

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
				printf("보스의 공격을 방어했습니다.\n");
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
        printf("플레이어 공격\n");
		player->ActorEffects();
        monster->Takedamge(player->GetATK());
        if (!monster->IsAlive())
        {
            return true;
        }

        printf("몬스터 공격\n");
		monster->ActorEffects();
        MonsterTurnCounter++; 
        if (monster->GetLevel() > 3)
        {
            if (MonsterTurnCounter % 2 == 0)
            {
                printf("몬스터 스킬 사용\n");
                monster->UseSkill(player, inventory);
            }
            else
            {
                player->Takedamge(monster->GetATK());
            }
        }

        else if (monster->GetLevel() == 3 && !SkillUsed)
        {
            printf("몬스터 스킬 사용\n");
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



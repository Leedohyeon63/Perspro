#include "BattleManager.h"
#include<iostream>
BattleResult BattleManager::MonsterBattle(Player* player, Actor* monster)
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
			if (MonsterFight(player, monster))
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

BattleResult BattleManager::BossBattle(Player* player, Actor* monster)
{
	return BattleResult::LOSE;
}

bool BattleManager::MonsterFight(Player* player, Actor* monster)
{
    bool skillUsed = false;    
    int monsterTurnCounter = 0; 
    system("cls");
    while (player->IsAlive() && monster->IsAlive())
    {
        printf("플레이어 공격\n");
        monster->Takedamge(player->GetATK());

        if (!monster->IsAlive())
        {
            return true;
        }

        printf("몬스터 공격\n");
        monsterTurnCounter++; 

        if (monster->GetLevel() > 3)
        {
            if (monsterTurnCounter % 2 == 0)
            {
                printf(">> 몬스터가 스킬을 사용했다!\n");
                monster->Useskill(player);
            }
            else
            {
                player->Takedamge(monster->GetATK());
            }
        }

        else if (monster->GetLevel() == 3 && !skillUsed)
        {
            printf(">> 몬스터가 스킬을 사용했다!\n");
            monster->Useskill(player);
            skillUsed = true; 
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

bool BattleManager::IsAlive(Actor* actor)
{
	if (actor->GetHP()>0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

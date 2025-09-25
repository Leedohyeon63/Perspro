#include "GameManager.h"
#include <iostream>
#include <string>
using namespace std;
void GameManager::TextRpg()
{
	srand(static_cast<unsigned int>(time(NULL)));
	player = Player("플레이어", 5000, 10, 5);
	player.PlayerPosx = 1;
	player.PlayerPosy = 5;
	while (!Isdead)
	{
		int BattleTrigger = rand() % 10 + 1;
		map.printMap(StageTrigger, player.PlayerPosx, player.PlayerPosy);
		printf("현재 체력 : %d, 공격력 : %d ,회복용 오브 : %d, 돈 : %d\n",
			player.GetHP(), player.GetATK(), player.Getorb(), player.GetGold());
		printf("이동 : wasd, 회복 h, 인벤토리 : i, 아이템 사용 : u\n");
		printf("입력 : ");
		cin >> move;
		if (move == "h" || move == "H")
		{
			player.PlayerHealing(player.Getorb());
			player.Sethealorb(0);
			system("pause");
		}
		else if (move == "i"|| move == "I")
		{
			inven.PrintInventory();
			system("pause");

		}
		else if (move == "u"|| move == "U")
		{
			inven.WhatUse(player);
			system("pause");
		}
		else
		{
			player.move(move, StageTrigger);
			if (map.IsShop(StageTrigger, player.PlayerPosx, player.PlayerPosy))
			{
				shop.OpenShop();
			}
			else if (map.IsPotal(StageTrigger, player.PlayerPosx, player.PlayerPosy)) {
				if (BossClear)
				{
					Nextstage();
					BossClear = false;
					continue;
				}
				else
				{
					printf("보스 클리어 필요\n");
					system("pause");
				}

			}
			else if (map.IsBoss(StageTrigger, player.PlayerPosx, player.PlayerPosy)) {
				if (!BossClear)
				{
					BossBattlevnet(StageTrigger);
					system("pause");
				}
				else
				{
					printf("이미 클리어 한 보스다.\n");
					system("pause");
				}
			}
			else if (map.IsHidden(StageTrigger, player.PlayerPosx, player.PlayerPosy)) {

			}
			else if (StageTrigger!=5&&BattleTrigger < 3)
			{
				BattleEvent(StageTrigger);
				system("pause");
			}
			
		}
		system("cls");

	}
	printf("플레이어 사망..\n");
	return;
}

void GameManager::Nextstage()
{
	if (StageTrigger < MAxstage)
	{
		StageTrigger++;
	}
	player.PlayerPosx = 1;
	player.PlayerPosy = 1;
	system("cls");
}

void GameManager::BattleEvent(int Stage)
{
	CurrentMonster = CreateMonster::SpawnMonster(Stage);
	CurrentMonster->ShowInfo();
	auto Result = battleManager.MonsterBattle(&player, CurrentMonster, &inven);
	if (Result==BattleResult::WIN)
	{
		printf("플레이어 승리\n");
		printf("오브 %d개, 골드 %d원 획득\n",Stage*10, Stage*30);
		player.Sethealorb(player.Getorb()+ Stage * 10);
		player.SetGold(player.GetGold() + Stage * 30);
	}
	else if (Result == BattleResult::RUN)
	{
		printf("도망갔습니다.\n");
	}
	else if (Result == BattleResult::LOSE)
	{
		Isdead = true;
		return;
	}
	else
	{
		return;
	}
}

void GameManager::BossBattlevnet(int Stage)
{
	CurrentBoss = CreateMonster::SpawnBoss(Stage);
	CurrentBoss->ShowInfo();
	auto Result = battleManager.BossBattle(&player, CurrentBoss, &inven);
	if (Result == BattleResult::WIN)
	{
		printf("플레이어 승리\n");
		printf("오브 %d개, 골드 %d원 획득\n", Stage * 20, Stage * 130);
		printf("%s의 심장을 얻었다...\n",CurrentBoss->GetName().c_str());
		player.Sethealorb(player.Getorb() + Stage * 20);
		player.SetGold(player.GetGold() + Stage * 130);
		inven.BossReward(CurrentBoss);
		BossClear = true;
	}
	else if (Result == BattleResult::RUN)
	{
		printf("도망갔습니다.\n");
	}
	else if (Result == BattleResult::LOSE)
	{
		Isdead = true;
		return;
	}
	else
	{
		return;
	}
}

GameManager::GameManager()
	: CurrentMonster(nullptr)
{
}

GameManager::~GameManager()
{
	if (CurrentMonster != nullptr)
	{
		delete CurrentMonster;
		CurrentMonster = nullptr;
	}
}
#include "GameManager.h"
#include <iostream>
#include <string>
using namespace std;
void GameManager::TextRpg()
{
	srand(static_cast<unsigned int>(time(NULL)));
	player = Player("�÷��̾�", 5000, 10, 5);
	player.PlayerPosx = 1;
	player.PlayerPosy = 5;
	while (!Isdead)
	{
		int BattleTrigger = rand() % 10 + 1;
		map.printMap(StageTrigger, player.PlayerPosx, player.PlayerPosy);
		printf("���� ü�� : %d, ���ݷ� : %d ,ȸ���� ���� : %d, �� : %d\n",
			player.GetHP(), player.GetATK(), player.Getorb(), player.GetGold());
		printf("�̵� : wasd, ȸ�� h, �κ��丮 : i, ������ ��� : u\n");
		printf("�Է� : ");
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
					printf("���� Ŭ���� �ʿ�\n");
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
					printf("�̹� Ŭ���� �� ������.\n");
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
	printf("�÷��̾� ���..\n");
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
		printf("�÷��̾� �¸�\n");
		printf("���� %d��, ��� %d�� ȹ��\n",Stage*10, Stage*30);
		player.Sethealorb(player.Getorb()+ Stage * 10);
		player.SetGold(player.GetGold() + Stage * 30);
	}
	else if (Result == BattleResult::RUN)
	{
		printf("���������ϴ�.\n");
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
		printf("�÷��̾� �¸�\n");
		printf("���� %d��, ��� %d�� ȹ��\n", Stage * 20, Stage * 130);
		printf("%s�� ������ �����...\n",CurrentBoss->GetName().c_str());
		player.Sethealorb(player.Getorb() + Stage * 20);
		player.SetGold(player.GetGold() + Stage * 130);
		inven.BossReward(CurrentBoss);
		BossClear = true;
	}
	else if (Result == BattleResult::RUN)
	{
		printf("���������ϴ�.\n");
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
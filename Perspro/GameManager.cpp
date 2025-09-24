#include "GameManager.h"
#include <iostream>
#include <string>
using namespace std;
void GameManager::TextRpg()
{
	srand(time(NULL));
	player = Player("플레이어", 500, 22, 5);
	player.PlayerPosx = 1;
	player.PlayerPosy = 1;
	while (true)
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
			printf("%d 만큼 회복 \n", player.Getorb());
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
				Nextstage();
				continue;
			}
			else if (map.IsBoss(StageTrigger, player.PlayerPosx, player.PlayerPosy)) {
				
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
	currentMonster = CreateMonster::SpawnMonster(Stage);
	currentMonster->ShowInfo();
	auto result = battleManager.MonsterBattle(&player, currentMonster);

}

GameManager::GameManager()
	: currentMonster(nullptr)
{
}

GameManager::~GameManager()
{
	if (currentMonster != nullptr)
	{
		delete currentMonster;
		currentMonster = nullptr;
	}
}
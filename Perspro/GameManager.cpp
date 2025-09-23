#include "GameManager.h"
#include <iostream>
#include <string>
using namespace std;
void GameManager::TextRpg()
{
	player.PlayerPosx = 1;
	player.PlayerPosy = 1;
	while (true)
	{
		printMap(StageTrigger, player.PlayerPosx, player.PlayerPosy);
		printf("현재 체력 : %d, 공격력 : %d ,회복용 오브 : %d, 돈 : %d\n",
			player.GetHP(), player.GetATK(), player.Getorb(), player.GetGold());
		printf("이동 : wasd, 인벤토리 : i, 아이템 사용 : u\n");
		printf("입력 : ");
		cin >> move;
		if (move == "i"|| move == "I")
		{
			inven.PrintInventory();
			system("pause");

		}
		else if (move == "u"|| move == "U")
		{
			inven.WhatUse();
		}
		else
		{
			player.move(move, StageTrigger);
			if (IsShop(StageTrigger, player.PlayerPosx, player.PlayerPosy))
			{
				inven.OpenShop();
			}
			else if (IsPotal(StageTrigger, player.PlayerPosx, player.PlayerPosy)) {
				Nextstage();
				continue;
			}
			else if (IsBoss(StageTrigger, player.PlayerPosx, player.PlayerPosy)) {
				
			}
			else if (IsHidden(StageTrigger, player.PlayerPosx, player.PlayerPosy)) {

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

void GameManager::WhereStege()
{

}

GameManager::~GameManager()
{
}

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
		printf("���� ü�� : %d, ���ݷ� : %d ,ȸ���� ���� : %d, �� : %d\n",
			player.GetHP(), player.GetATK(), player.Getorb(), player.GetGold());
		printf("�̵� : wasd, �κ��丮 : i, ������ ��� : u\n");
		printf("�Է� : ");
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

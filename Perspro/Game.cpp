#include "Game.h"
#include <iostream>
#include <string>
using namespace std;
void Game::TextRpg()
{
	player.PlayerPosx = 1;
	player.PlayerPosy = 1;
	while (true)
	{
		printMap(StageTrigger, player.PlayerPosx, player.PlayerPosy);
		printf("���� ü�� : %d, ���ݷ� : %d ,ȸ���� ���� : %d, �� : %d\n",
			player.GetHP(), player.GetATK(), player.Getorb(), player.GetGold());
		printf("�̵� : wasd, ȸ�� : h, �κ��丮 : i, ������ ��� : e\n");
		printf("�Է� : ");
		cin >> move;
		if (move == "h")
		{
			if (player.Getorb() > 0)
			{
				printf("%d�� ü�� ȸ�� ", player.Getorb());
				player.PlayerHealing(player.Getorb());
				player.Sethealorb(0);
			}
			else
			{
				printf("���� ����\n");
				system("pause");
			}
		}
		else if (move == "i")
		{
			inven.PrintInventory();
		}
		else if (move == "e")
		{
			inven.UseItem();
		}
		else
		{
			player.move(move, StageTrigger);
			if (IsShop(StageTrigger, player.PlayerPosx, player.PlayerPosy))
			{

			}
			else if (IsPotal(StageTrigger, player.PlayerPosx, player.PlayerPosy)) {
				Nextstage();
				continue;
			}
			else if (IsBoss(StageTrigger, player.PlayerPosx, player.PlayerPosy)) {
				
			}
		}
		system("cls");
	}
}

void Game::Nextstage()
{
	if (StageTrigger < MAxstage)
	{
		StageTrigger++;
	}
	player.PlayerPosx = 1;
	player.PlayerPosy = 1;
	system("cls");
}

void Game::WhereStege()
{

}

Game::~Game()
{
}

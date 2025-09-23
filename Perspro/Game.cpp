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
		printf("현재 체력 : %d, 공격력 : %d ,회복용 오브 : %d, 돈 : %d\n",
			player.GetHP(), player.GetATK(), player.Getorb(), player.GetGold());
		printf("이동 : wasd, 회복 : h, 인벤토리 : i, 아이템 사용 : e\n");
		printf("입력 : ");
		cin >> move;
		if (move == "h")
		{
			if (player.Getorb() > 0)
			{
				printf("%d의 체력 회복 ", player.Getorb());
				player.PlayerHealing(player.Getorb());
				player.Sethealorb(0);
			}
			else
			{
				printf("오브 없음\n");
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

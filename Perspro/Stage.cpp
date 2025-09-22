#include "Stage.h"
#include <iostream>
#include <string>
using namespace std;
Stage::Stage()
{
}

Stage::~Stage()
{
}
void Stage::TextRpg()
{
	int StageTrigger = 3;
	string move;
	Player player = Player("플레이어", 100, 20);
	player.PlayerPosx = 1;
	player.PlayerPosy = 1;
	StageMap stagemap;
	while (true)
	{
		stagemap.printMap(StageTrigger, player.PlayerPosx, player.PlayerPosy);
		cin >> move;
		
		if ((move == "d" || move == "D")&& Iswall(StageTrigger, player.PlayerPosx, player.PlayerPosy, Way::Right))
		{
			player.move(player.PlayerPosx + 1, player.PlayerPosy);

		}
		else if ((move == "h" || move == "H"))
		{
			player.Healing(player.Getorb());
			player.Sethealorb(0);
		}
		else
		{
			printf("=================\n");
			printf("잘못된 이동입니다,\n");
			printf("=================\n");
		}
	}
}

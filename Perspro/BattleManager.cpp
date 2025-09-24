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
		if (Choise == 1)
		{
			return BattleResult::WIN;

		}
		else if (Choise == 2)
		{
			printf("도망갔습니다.\n");
			player->PlayerDmagetaken(10);
			return BattleResult::LOSE;
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

#include "BattleManager.h"
#include<iostream>
BattleResult BattleManager::MonsterBattle(Player* player, Actor* monster)
{
	auto Choise = 0;
	printf("1. �ο� 2. ���� : ");
	cin >> Choise;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "�߸��� �Է��Դϴ�. �г�Ƽ.\n";
		player->PlayerDmagetaken(30);
	}
	else {
		if (Choise == 1)
		{
			return BattleResult::WIN;

		}
		else if (Choise == 2)
		{
			printf("���������ϴ�.\n");
			player->PlayerDmagetaken(10);
			return BattleResult::LOSE;
		}
		else
		{
			printf("�߸��� �Է�\n");
			return BattleResult::ERROR;
		}
	}
	return BattleResult::ERROR;
}

BattleResult BattleManager::BossBattle(Player* player, Actor* monster)
{
	return BattleResult::LOSE;
}

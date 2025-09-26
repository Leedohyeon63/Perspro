#include "GameManager.h"//���� ������ �����ϴ� Ŭ����
#include <iostream>
#include <string>
using namespace std;
void GameManager::TextRpg()//�ؽ�Ʈ ������ ���� �����ϴ� �޼ҵ�
{
	srand(static_cast<unsigned int>(time(NULL)));
	player = Player("�÷��̾�", 500, 22, 5);
	player.SetGold(100);
	player.PlayerPosx = 2;//�÷��̾� ���� ��ǥ
	player.PlayerPosy = 2;//����
	while (!Isdead)
	{
		if (IsClear)
		{
			system("cls");
			printf("�����մϴ�. ������ Ŭ���� �ϼ̽��ϴ�.");
			return;
		}
		int BattleTrigger = rand() % 10 + 1;
		map.printMap(StageTrigger, player.PlayerPosx, player.PlayerPosy);
		printf("���� ü�� : %d, ���ݷ� : %d ,ȸ���� ���� : %d, �� : %d\n",
			player.GetHP(), player.GetATK(), player.Getorb(), player.GetGold());
		printf("�̵� : wasd, ȸ�� h, �κ��丮 : i, ������ ��� : u, ������ ���� : e, ������ ���� : r\n");
		printf("�Է� : ");
		cin >> move;
		if (move == "h" || move == "H")//�÷��̾� �̵�, ȸ��, ������ ���� ����
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
		else if (move == "e" || move == "E")
		{
			inven.EquipItem();
			system("pause");
		}
		else if (move == "r" || move == "R")
		{
			inven.UnEquipItem();
			system("pause");
		}
		else
		{
			player.move(move, StageTrigger);//�÷��̾� �̵��� ��������, �������� ��� �Ǻ��ϴ� �κ�
			if (map.IsShop(StageTrigger, player.PlayerPosx, player.PlayerPosy))
			{
				shop.LoadItem(StageTrigger,&inven);//���������� ���� ���� ����
				shop.OpenShop(&player, &inven);//�� ������ ����
			}
			else if (map.IsPotal(StageTrigger, player.PlayerPosx, player.PlayerPosy))
			{
				Nextstage();
				BossClear = false;
				shop.NotVisit = true;
				continue;
			}
			else if (map.IsBoss(StageTrigger, player.PlayerPosx, player.PlayerPosy)) 
			{
				if (!BossClear)
				{
					BossBattlevnet(StageTrigger);
					system("pause");
				}
				else
				{
					printf("�̹� Ŭ���� �� ������.\n");//���� �絵�� �Ұ���
					system("pause");
				}
			}
			else if (map.IsAlter(StageTrigger, player.PlayerPosx, player.PlayerPosy, inven))
			{
				if (inven.FindListItem("���ֺ�"))
				{
					IsClear = true;
				}
				else
				{
					printf("������ ���� ���ߴ�..\n");
					player.PlayerPosx = 2;
					player.PlayerPosy = 2;
					StageTrigger--;
					system("pause");
					system("cls");

				}
				continue;
			}
			else if (StageTrigger<5&&BattleTrigger < 3)//5&6��������(������ ��������)�� ������ ������ ���������� �ൿ�� �� ���� 30�� Ȯ���� ���� ��Ʋ
			{
				BattleEvent(StageTrigger);
				system("pause");
			}
			
		}
		system("cls");

	}
	printf("�÷��̾� ���..\n");//���� ����� ���� �������
	return;
}

void GameManager::Nextstage()//���� ���������� ���� �޼ҵ�
{
	if (StageTrigger < MAxstage)
	{
		StageTrigger++;
	}
	player.PlayerPosx = 2;
	player.PlayerPosy = 2;
	system("cls");
}

void GameManager::BattleEvent(int Stage)//�Ϲ� ���Ϳ��� ������ �����ϰ� ����� �����ϴ� �޼ҵ�
{
	CurrentMonster = CreateMonster::SpawnMonster(Stage);
	CurrentMonster->ShowInfo();
	int Reward = (CurrentMonster->GetLevel() * 5) + (Stage * 5) + 5;
	auto Result = battleManager.MonsterBattle(&player, CurrentMonster, &inven);
	if (Result==BattleResult::WIN)//����� enum�� ���� ���� ��� ���
	{
		printf("�÷��̾� �¸�\n");
		printf("���� %d��, ��� %d�� ȹ��\n",Stage*10, Stage*30);
		player.Sethealorb(player.Getorb()+ Reward);
		player.SetGold(player.GetGold() + 3*Reward);
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

void GameManager::BossBattlevnet(int Stage)//���� ���Ϳ��� ������ �����ϰ� ����� �����ϴ� �޼ҵ�
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
		inven.BossReward(CurrentBoss);//������ ���� ���� ����
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
	if (CurrentBoss != nullptr)
	{
		delete CurrentBoss;
		CurrentBoss = nullptr;
	}
}
#include "GameManager.h"//게임 전반을 관리하는 클래스
#include <iostream>
#include <string>
using namespace std;
void GameManager::TextRpg()//텍스트 알피지 게임 실행하는 메소드
{
	srand(static_cast<unsigned int>(time(NULL)));
	player = Player("플레이어", 500, 22, 5);
	player.SetGold(100);
	player.PlayerPosx = 2;//플레이어 스폰 좌표
	player.PlayerPosy = 2;//동일
	while (!Isdead)
	{
		if (IsClear)
		{
			system("cls");
			printf("축하합니다. 게임을 클리어 하셨습니다.");
			return;
		}
		int BattleTrigger = rand() % 10 + 1;
		map.printMap(StageTrigger, player.PlayerPosx, player.PlayerPosy);
		printf("현재 체력 : %d, 공격력 : %d ,회복용 오브 : %d, 돈 : %d\n",
			player.GetHP(), player.GetATK(), player.Getorb(), player.GetGold());
		printf("이동 : wasd, 회복 h, 인벤토리 : i, 아이템 사용 : u, 아이템 장착 : e, 아이템 해제 : r\n");
		printf("입력 : ");
		cin >> move;
		if (move == "h" || move == "H")//플레이어 이동, 회복, 아이템 사용과 장착
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
			player.move(move, StageTrigger);//플레이어 이동과 상점인지, 보스인지 등등 판별하는 부분
			if (map.IsShop(StageTrigger, player.PlayerPosx, player.PlayerPosy))
			{
				shop.LoadItem(StageTrigger,&inven);//스테이지에 따라 상점 생성
				shop.OpenShop(&player, &inven);//그 상점을 열음
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
					printf("이미 클리어 한 보스다.\n");//보스 재도전 불가능
					system("pause");
				}
			}
			else if (map.IsAlter(StageTrigger, player.PlayerPosx, player.PlayerPosy, inven))
			{
				if (inven.FindListItem("지휘봉"))
				{
					IsClear = true;
				}
				else
				{
					printf("보스를 잡지 못했다..\n");
					player.PlayerPosx = 2;
					player.PlayerPosy = 2;
					StageTrigger--;
					system("pause");
					system("cls");

				}
				continue;
			}
			else if (StageTrigger<5&&BattleTrigger < 3)//5&6스테이지(마지막 스테이지)를 제외한 나머지 스테이지는 행동할 때 마다 30퍼 확률로 몬스터 배틀
			{
				BattleEvent(StageTrigger);
				system("pause");
			}
			
		}
		system("cls");

	}
	printf("플레이어 사망..\n");//게임 종료시 나올 사망문구
	return;
}

void GameManager::Nextstage()//다음 스테이지로 가는 메소드
{
	if (StageTrigger < MAxstage)
	{
		StageTrigger++;
	}
	player.PlayerPosx = 2;
	player.PlayerPosy = 2;
	system("cls");
}

void GameManager::BattleEvent(int Stage)//일반 몬스터와의 전투를 시작하고 결과를 리턴하는 메소드
{
	CurrentMonster = CreateMonster::SpawnMonster(Stage);
	CurrentMonster->ShowInfo();
	int Reward = (CurrentMonster->GetLevel() * 5) + (Stage * 5) + 5;
	auto Result = battleManager.MonsterBattle(&player, CurrentMonster, &inven);
	if (Result==BattleResult::WIN)//결과값 enum에 따라 전투 결과 출력
	{
		printf("플레이어 승리\n");
		printf("오브 %d개, 골드 %d원 획득\n",Stage*10, Stage*30);
		player.Sethealorb(player.Getorb()+ Reward);
		player.SetGold(player.GetGold() + 3*Reward);
	}
	else if (Result == BattleResult::RUN)
	{
		printf("도망갔습니다.\n");
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

void GameManager::BossBattlevnet(int Stage)//보스 몬스터와의 전투를 시작하고 결과를 리턴하는 메소드
{
	CurrentBoss = CreateMonster::SpawnBoss(Stage);
	CurrentBoss->ShowInfo();
	auto Result = battleManager.BossBattle(&player, CurrentBoss, &inven);
	if (Result == BattleResult::WIN)
	{
		printf("플레이어 승리\n");
		printf("오브 %d개, 골드 %d원 획득\n", Stage * 20, Stage * 130);
		printf("%s의 심장을 얻었다...\n",CurrentBoss->GetName().c_str());
		player.Sethealorb(player.Getorb() + Stage * 20);
		player.SetGold(player.GetGold() + Stage * 130);
		inven.BossReward(CurrentBoss);//보스는 개별 보상 존재
		BossClear = true;
	}
	else if (Result == BattleResult::RUN)
	{
		printf("도망갔습니다.\n");
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
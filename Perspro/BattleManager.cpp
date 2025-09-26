#include "BattleManager.h"
#include<iostream>
//전투 관련 함수를 관리하는 클래스
BattleResult BattleManager::MonsterBattle(Player* player, Actor* monster, Inventory* inventory)
{//일반 몬스터와의 전투여부를 정하고 전투 결과를 리턴하는 메소드
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
		if (Choise == 1 && monster->GetLevel())
		{
			if (MonsterFight(player, monster, inventory))//실질적인 전투는 MonsterFight
			{
				return BattleResult::WIN;
			}
			else
			{
				return BattleResult::LOSE;
			}

		}
		else if (Choise == 2)
		{
			player->PlayerDmagetaken(10);
			player->Sethealorb(player->Getorb()/3);
			player->SetGold(player->GetGold()/2);//도망시 패널티로 오브 66퍼, 돈 50퍼 가져감
			return BattleResult::RUN;
		}
		else
		{
			printf("잘못된 입력\n");
			return BattleResult::ERROR;
		}
	}
	return BattleResult::ERROR;
}

BattleResult BattleManager::BossBattle(Player* player, Actor* boss, Inventory* inventory)
{//보스 몬스터와의 전투여부를 정하고 전투 결과를 리턴하는 메소드
	auto Choise = 0;
	printf("보스에 도전하시겠습니까? (1. 네/2. 아니오) : ");
	cin >> Choise;
	if (cin.fail()) 
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "잘못된 입력입니다.\n";
	}
	else {
		if (Choise == 1)
		{
			if (BossFight(player, boss, inventory))//몬스터일 경우와 동일하게 실질적인 전투는 다른 메소드에서 함
			{
				return BattleResult::WIN;
			}
			else
			{
				return BattleResult::LOSE;
			}
		}
		else if (Choise == 2)
		{
			return BattleResult::RUN;
		}
	}

		return BattleResult::ERROR;
}


bool BattleManager::BossFight(Player* player, Actor* boss, Inventory* inventory)
{//보스 몬스터와 전투하는 메소드
	MonsterTurnCounter = 0;//스킬 사용을 위해 몬스터 턴을 표시해주는 메소드, 보스는 보스마다 패턴의 개수가 달라서 0으로 초기화
	int GuardCoolDown = 0;//가드 쿨타임 0일때 준비 완료
	system("cls");
    while (player->IsAlive() && boss->IsAlive())
    {
		auto Choise = 0;
		MonsterTurnCounter++;
		printf("1. 공격 / 2. 회복(오브 %d 개) / 3. 아이템 사용 ",player->Getorb()); 
		if (GuardCoolDown == 0) 
		{
			printf("4. 가드(가능) : ");
		}
		else
		{ 
			printf("3. 가드(불가능, %d턴 남음) : ", GuardCoolDown);//가드는 5턴의 쿨타임이 있지만 보스의 다음 공격을 그냥 넘기게 해줌
		}
		cin >> Choise;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "잘못된 입력입니다.\n";
			if (MonsterTurnCounter>1)
			{
				MonsterTurnCounter--;
			}
			continue;
		}
		else {
			if (Choise == 1)
			{
				player->ActorEffects();
				printf("\n플레이어 공격\n");
				boss->Takedamge(player->GetATK());
				if (!boss->IsAlive())
				{
					return true;
				}
				printf("\n보스 공격\n");
				boss->UsePattern(player, inventory, MonsterTurnCounter);
				if (!player->IsAlive())
				{
					return false;
				}
				if (GuardCoolDown!=0)
				{
					GuardCoolDown--;
				}
			}
			else if (Choise == 2)
			{
				if (!(player->IsHealBlocked()))
				{
					player->PlayerHealing(player->Getorb());
					player->Sethealorb(0);
				}
				else
				{
					printf("현재 회복 불가능");

				}
				player->Takedamge(boss->GetATK());

			}
			else if (Choise == 3)
			{
				inventory->BattleUse(*player);
				player->Takedamge(boss->GetATK());
			}
			else if (Choise == 4)
			{
				printf("보스의 공격을 방어했습니다.\n");
				GuardCoolDown = 5;
				continue;
			}
		}
    }
	return false;
}


bool BattleManager::MonsterFight(Player* player, Actor* monster, Inventory* inventory)
{//일반 몬스터와 전투하는 메소드
    system("cls");
    while (player->IsAlive() && monster->IsAlive())
    {
        printf("플레이어 공격\n");
		player->ActorEffects();
        monster->Takedamge(player->GetATK());
        if (!monster->IsAlive())
        {
            return true;
        }

        printf("몬스터 공격\n");
		monster->ActorEffects();
        MonsterTurnCounter++; //스킬 사용을 위해 몬스터 턴을 표시해주는 메소드
        if (monster->GetLevel() > 3)//몬스터 레벨에 따라 스킬 패턴이 다름 3이상은 두번째 공격마다 한번,
        {							//2는 시작할때 한번, 1은 기본 공격만 실행 
            if (MonsterTurnCounter % 2 == 0)
            {
                printf("몬스터 스킬 사용\n");
                monster->UseSkill(player, inventory);
            }
            else
            {
                player->Takedamge(monster->GetATK());
            }
        }

        else if (monster->GetLevel() == 3 && !SkillUsed)
        {
            printf("몬스터 스킬 사용\n");
            monster->UseSkill(player, inventory);
            SkillUsed = true; 
        }
        else
        {
            player->Takedamge(monster->GetATK());
        }

        if (!player->IsAlive())
        {
            return false; 
        }

    }
    return player->IsAlive();
}



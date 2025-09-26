#include "Inventory.h"//인벤토리와 인벤토리 내의 모든 작업을 관리하는 클래스
#include<iostream>

void Inventory::PrintInventory()//인벤토리 출력
{
	printf("인벤토리 내역\n");
	printf("\n==============장착중==============\n");
	for (int i = 0; i < EquipList.size(); i++)
	{
		cout << "(" << EquipList[i] << ")" << " ";
	}
	printf("\n==============소지품==============\n");
	for (int i = 0; i < InventoryList.size(); i++)
	{
		cout << "(" << InventoryList[i] << ")" << " ";
	}
	printf("\n==============소모품==============\n");
	for (int i = 0; i < ConsumablesList.size(); i++)
	{
		cout << "(" << ConsumablesList[i] << ")" << " ";
	}
	printf("\n==============전투도구==============\n");
	for (int i = 0; i < BattleList.size(); i++)
	{
		cout << "(" << BattleList[i] << ")" << " ";
	}
	printf("\n");
}


void Inventory::WhatUse(Player& player)//아이템 사용하는 메소드 소모품과 전투도구 두가지를 구분한다.
{
	string Choise;
	printf("사용할 아이템 선택\n");
	printf("==============소모품==============\n");
	for (int i = 0; i < ConsumablesList.size(); i++)
	{
		cout << "(" << ConsumablesList[i] << ")" << " ";
	}
	printf("\n");
	printf("\n==============전투도구==============\n");
	for (int i = 0; i < BattleList.size(); i++)
	{
		cout << "(" << BattleList[i] << ")" << " ";
	}
	printf("\n");
	cin >> Choise;

	if (find(ConsumablesList.begin(), ConsumablesList.end(), Choise) != ConsumablesList.end())//소모품과 전투 도구 배열을 돌면서 아이템 있는지 확인
	{
		UseItem(Choise, player);
	}
	else if (find(BattleList.begin(), BattleList.end(), Choise) != BattleList.end())
	{
		UseItem(Choise, player);
	}
	else
	{
		cout << "'" << Choise << "'은(는) 사용할 수 없는 아이템입니다." << endl;
	}
	return;
}
void Inventory::BattleUse(Player& player)//보스 전투시에는 전투도구만 사용 가능한데 그때 사용하는 메소드
{
	string Choise;
	printf("사용할 아이템 선택\n");
	printf("==============전투도구=============\n");
	for (int i = 0; i < BattleList.size(); i++)
	{
		cout << "(" << BattleList[i] << ")" << " ";
	}
	printf("\n");
	cin >> Choise;
	if (find(BattleList.begin(), BattleList.end(), Choise) != BattleList.end())
	{
		UseItem(Choise, player);
	}
	return;
}

void Inventory::BossReward(Actor* Boss)//보스에 따라 보상을 지급하는 메소드
{
	if (Boss->GetName()=="토르비오")
	{
		InventoryList.push_back("화려한 심장");
		ConsumablesList.push_back("화려한깃털");
	}
	else if (Boss->GetName() == "나이레스")
	{
		InventoryList.push_back("숲의 심장");
		ConsumablesList.push_back("자연의정수");
	}
	else if (Boss->GetName() == "위대한 그롤")
	{
		InventoryList.push_back("역겨운 심장");
		ConsumablesList.push_back("영혼주머니");
	}
	else if (Boss->GetName() == "위대한 어머니 실크")
	{
		InventoryList.push_back("실로 만든 심장");
		ConsumablesList.push_back("창백한발톱조각");
	}
	else if (Boss->GetName() == "풀려난 자")
	{
		InventoryList.push_back("지휘봉");
	}
}

void Inventory::EquipItem()//아이템을 장착하는 메소드. 장착한 아이템에 따라 특정 보스나 몬스터의 데미지를 크게 줄일수 있다
{
	string Choise;
	printf("\n==============소지품==============\n");
	for (int i = 0; i < InventoryList.size(); i++)
	{
		cout << "(" << InventoryList[i] << ")" << " ";
	}
	printf("\n장착할 도구 선택 : ");
	cin >> Choise;
	auto iter = find(InventoryList.begin(), InventoryList.end(), Choise);
	if (iter != InventoryList.end())
	{
		EquipList.push_back(*iter);
		InventoryList.erase(iter);
		printf("아이템을 장착합니다..\n");
	}
	else
	{
		printf("아이템이 없습니다..\n");
	}
}
void Inventory::UnEquipItem()//아이템을 해제하는 메소드
{
	string Choise;
	printf("\n해제할 도구 선택\n");
	printf("\n==============장착중==============\n");
	for (int i = 0; i < EquipList.size(); i++)
	{
		cout << "(" << EquipList[i] << ")" << " ";
	}
	cin >> Choise;
	auto iter = find(EquipList.begin(), EquipList.end(), Choise);
	if (iter != EquipList.end())
	{
		InventoryList.push_back(*iter);
		EquipList.erase(iter);
		printf("아이템을 해제합니다..\n");
	}
	else
	{
		printf("아이템을 장착하지 않았습니다..\n");
	}
}
void Inventory::UseItem(string Choise, Player& player)//아이템을 사용하는 메소드
{
	if (Choise == "화려한깃털")
	{
		player.PlayerDmageSet(player.GetATK() + FeatherATk);
		player.PlayerHealing(300);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "자연의정수")
	{
		player.SetMaxHealth(player.GetMaxHealth() + NatureHealth);
		player.PlayerDmageSet(player.GetATK() + FeatherATk/2);
		player.PlayerHealing(1000);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "영혼주머니")
	{
		player.SetMaxHealth(player.GetMaxHealth() + SoulHealth);
		player.PlayerHealing(1000);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "창백한발톱조각")
	{
		player.PlayerDmageSet(player.GetATK() + SilkATK);
		player.SetMaxHealth(player.GetMaxHealth() + SilkHealth);
		player.PlayerHealing(1000);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "회복물약")
	{
		player.PlayerHealing(50);
		DeleteBattleItem(Choise);
	}
	else if (Choise == "고급물약")
	{
		player.PlayerHealing(70);
		DeleteBattleItem(Choise);
	}
	else if (Choise == "벼룩주")
	{
		player.PlayerHealing(150);
		DeleteBattleItem(Choise);
	}
	else if (Choise == "부싯깃")
	{
		player.ActorDamgeBuff(4, 30);
		DeleteBattleItem(Choise);
	}
	else if (Choise == "재생의부적")
	{
		player.ActorHealthRegen(5, 40);
		DeleteBattleItem(Choise);
	}
	else if (Choise == "기사의심장")
	{
		player.ActorDamgeBuff(20, 20);
		DeleteBattleItem(Choise);
	}
	else if (Choise == "낡은심장")
	{
		player.SetMaxHealth(player.GetMaxHealth() + 50);
		player.PlayerHealing(100);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "용의심장")
	{
		player.PlayerDmageSet(player.GetATK() + 10);
		player.SetMaxHealth(player.GetMaxHealth() + 70);
		player.PlayerHealing(100);
		DeleteConsumablesItem(Choise);
	}
	return;
}

void Inventory::PushItem(string item, string type)//아이템을 분류에 따라 벡터에 넣는 메소드
{
	if (type == "전투")
	{
		BattleList.push_back(item);
		return;
	}
	else if (type == "소지품")
	{
		InventoryList.push_back(item);
		return;
	}
	else if (type == "소모품")
	{
		ConsumablesList.push_back(item);
		return;
	}
	
}
bool Inventory::FindListItem(string item)//소지품 존재 유무를 확인하는 메소드
{
	for (vector<string>::iterator iter = InventoryList.begin(); iter != InventoryList.end(); iter++)
	{
		if (*iter == item)
		{
			return true;
		}
	}
	return false;
}
bool Inventory::IsEquip(string item)//장착 유무를 확인하는 메소드
{
	for (vector<string>::iterator iter = EquipList.begin(); iter != EquipList.end(); iter++)
	{
		if (*iter == item)
		{
			return true;
		}
	}
	return false;
}

void Inventory::DeleteItem(string item)//소지품 삭제하는 메소드
{
	for (vector<string>::iterator iter = InventoryList.begin(); iter != InventoryList.end(); iter++)
	{
		if (*iter == item)
		{
			InventoryList.erase(iter);
			return;
		}
	}
	return;
}

void Inventory::DeleteConsumablesItem(string item)//소모품 삭제하는 메소드
{
	for (vector<string>::iterator iter = ConsumablesList.begin(); iter != ConsumablesList.end(); iter++)
	{
		if (*iter == item)
		{
			ConsumablesList.erase(iter);
			return;
		}
	}
}
void Inventory::DeleteBattleItem(string item)//전투도구 삭제하는 메소드
{
	for (vector<string>::iterator iter = BattleList.begin(); iter != BattleList.end(); iter++)
	{
		if (*iter == item)
		{
			BattleList.erase(iter);
			return;
		}
	}
}

void Inventory::RecordItem(const std::string& itemName)
{
	if (!RecordUniqueItem(itemName)) {
		UniqueItems.push_back(itemName);
	}
}

bool Inventory::RecordUniqueItem(const std::string& itemName) const
{
	auto iter = std::find(UniqueItems.begin(), UniqueItems.end(), itemName);
	return iter != UniqueItems.end();
}
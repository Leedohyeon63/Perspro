#include "Inventory.h"
#include<iostream>

void Inventory::PrintInventory()
{
	printf("인벤토리 내역\n");
	printf("==============장착중==============\n");
	for (int i = 0; i < EquipList.size(); i++)
	{
		cout << "(" << EquipList[i] << ")" << " ";
	}
	printf("==============소모품==============\n");
	for (int i = 0; i < InventoryList.size(); i++)
	{
		cout << "(" << InventoryList[i] << ")" << " ";
	}
	printf("\n==============소지품==============\n");
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


void Inventory::WhatUse(Player& player)
{
	string Choise;
	printf("사용할 아이템 선택\n");
	printf("==============소모품==============\n");
	for (int i = 0; i < ConsumablesList.size(); i++)
	{
		cout << "(" << ConsumablesList[i] << ")" << " ";
	}
	printf("\n");
	cin >> Choise;
	if (find(ConsumablesList.begin(), ConsumablesList.end(), Choise) != ConsumablesList.end())
	{
		UseItem(Choise, player);
	}
	return;
}
void Inventory::BattleUse(Player& player)
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

void Inventory::BossReward(Actor* Boss)
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
}

void Inventory::UseItem(string Choise, Player& player)
{
	if (Choise == "화려한깃털")
	{
		player.PlayerDmageSet(player.GetATK() + FeatherATk);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "자연의정수")
	{
		player.SetMaxHealth(player.GetMaxHealth() + NatureHealth);
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
	return;
}

void Inventory::PushItem(string item, string type)
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

bool Inventory::FindItem(string item)
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

void Inventory::DeleteItem(string item)
{
	for (vector<string>::iterator iter = InventoryList.begin(); iter != InventoryList.end(); iter++)
	{
		if (*iter == item)
		{
			InventoryList.erase(iter);
		}
	}
	return;
}

void Inventory::DeleteConsumablesItem(string item)
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

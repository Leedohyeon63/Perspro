#pragma once
#include "Shop.h"
#include "header.h"
#include "Player.h"
#include<vector>
class Actor;
class Inventory
{
public:
	void PrintInventory();
	void UseItem(string Choise, Player& player);
	void PushItem(string item, string type);
	bool FindItem(string item);
	void DeleteItem(string item);
	void DeleteConsumablesItem(string item);
	void WhatUse(Player& player);
	void BattleUse(Player& player);
	void BossReward(Actor* Boss);
protected:
	int Maxinven = 10;
	std::vector<string> InventoryList = {"팬던트", "대못", "순수의 화환"};
	std::vector<string> EquipList = {"팬던트", "대못", "폴립 심장"};
	std::vector<string> ConsumablesList = {"화려한깃털" ,"자연의정수","영혼주머니","창백한발톱조각" };
	std::vector<string> BattleList = {"부싯깃"};
	int FeatherATk = 10;
	int SilkATK = 50;
	int NatureHealth = 100;
	int SoulHealth = 100;
	int SilkHealth = 100;
};


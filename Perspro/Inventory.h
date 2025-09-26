#pragma once
#include "Shop.h"
#include "header.h"
#include "Player.h"
#include<vector>
#include <algorithm>
class Actor;
class Inventory
{
public:
	void PrintInventory();
	void UseItem(string Choise, Player& player);
	void PushItem(string item, string type);
	bool IsEquip(string item);
	bool FindListItem(string item);
	void DeleteItem(string item);
	void DeleteConsumablesItem(string item);
	void DeleteBattleItem(string item);
	void WhatUse(Player& player);
	void BattleUse(Player& player);
	void BossReward(Actor* Boss);
	void EquipItem();
	void UnEquipItem();
	void RecordItem(const std::string& itemName);
	bool RecordUniqueItem(const std::string& itemName) const;
protected:
	std::vector<std::string> UniqueItems;
	std::vector<string> InventoryList = {"ÆÒ´øÆ®", "´ë¸ø"};
	std::vector<string> EquipList = {};
	std::vector<string> ConsumablesList = {};
	std::vector<string> BattleList = {};
	int FeatherATk = 10;
	int SilkATK = 50;
	int NatureHealth = 100;
	int SoulHealth = 100;
	int SilkHealth = 100;
};


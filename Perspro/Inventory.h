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
	std::vector<string> InventoryList = {"�Ҵ�Ʈ", "���", "������ ȭȯ"};
	std::vector<string> EquipList = {"�Ҵ�Ʈ", "���", "���� ����"};
	std::vector<string> ConsumablesList = {"ȭ���ѱ���" ,"�ڿ�������","��ȥ�ָӴ�","â���ѹ�������" };
	std::vector<string> BattleList = {"�ν˱�"};
	int FeatherATk = 10;
	int SilkATK = 50;
	int NatureHealth = 100;
	int SoulHealth = 100;
	int SilkHealth = 100;
};


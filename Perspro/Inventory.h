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
	void PushItem(string item);
	bool FindItem(string item);
	void DeleteItem(string item);
	void PushConsumablesItem(string item);
	void DeleteConsumablesItem(string item);
	void WhatUse(Player& player);
	void BossReward(Actor* Boss);
protected:
	int Maxinven = 10;
	std::vector<string> InventoryList = {"ÆÒ´øÆ®", "´ë¸ø", "¼ø¼öÀÇ È­È¯"};
	std::vector<string> ConsumablesList = {"ºÎ½Ë±ê"};

};


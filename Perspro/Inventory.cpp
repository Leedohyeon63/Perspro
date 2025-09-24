#include "Inventory.h"
#include<iostream>

void Inventory::PrintInventory()
{
	printf("�κ��丮 ����\n");
	printf("==============�Ҹ�ǰ==============\n");
	for (int i = 0; i < InventoryList.size(); i++)
	{
		cout << "(" << InventoryList[i] << ")" << " ";
	}
	printf("\n==============����ǰ==============\n");
	for (int i = 0; i < ConsumablesList.size(); i++)
	{
		cout << "(" << ConsumablesList[i] << ")" << " ";
	}
	printf("\n");
}


void Inventory::WhatUse(Player& player)
{
	string Choise;
	printf("����� ������ ����\n");
	printf("==============�Ҹ�ǰ==============\n");
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

void Inventory::UseItem(string Choise, Player& player)
{
	if (Choise == "�ν˱�")
	{
		player.PlayerDmageSet(player.GetATK()+10);
		player.PlayerDmagetaken(20);
		printf("������ %d.\n", player.GetATK());

	}
	DeleteConsumablesItem(Choise);
	return;
}

void Inventory::PushItem(string item)
{
	InventoryList.push_back(item);
	return;
}

void Inventory::DeleteItem(string item)
{
	for (vector<string>::iterator iter = InventoryList.begin(); iter != InventoryList.end(); iter++)
	{
		if (*iter == item)
		{
			*iter = InventoryList.back();
			InventoryList.pop_back();
		}
	}
	return;
}

void Inventory::PushConsumablesItem(string item)
{
	ConsumablesList.push_back(item);
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

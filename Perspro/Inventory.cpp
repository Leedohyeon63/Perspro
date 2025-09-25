#include "Inventory.h"
#include<iostream>

void Inventory::PrintInventory()
{
	printf("�κ��丮 ����\n");
	printf("==============������==============\n");
	for (int i = 0; i < EquipList.size(); i++)
	{
		cout << "(" << EquipList[i] << ")" << " ";
	}
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
	printf("\n==============��������==============\n");
	for (int i = 0; i < BattleList.size(); i++)
	{
		cout << "(" << BattleList[i] << ")" << " ";
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
void Inventory::BattleUse(Player& player)
{
	string Choise;
	printf("����� ������ ����\n");
	printf("==============��������=============\n");
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
	if (Boss->GetName()=="�丣���")
	{
		InventoryList.push_back("ȭ���� ����");
		ConsumablesList.push_back("ȭ���ѱ���");
	}
	else if (Boss->GetName() == "���̷���")
	{
		InventoryList.push_back("���� ����");
		ConsumablesList.push_back("�ڿ�������");
	}
	else if (Boss->GetName() == "������ �׷�")
	{
		InventoryList.push_back("���ܿ� ����");
		ConsumablesList.push_back("��ȥ�ָӴ�");
	}
	else if (Boss->GetName() == "������ ��Ӵ� ��ũ")
	{
		InventoryList.push_back("�Ƿ� ���� ����");
		ConsumablesList.push_back("â���ѹ�������");
	}
}

void Inventory::UseItem(string Choise, Player& player)
{
	if (Choise == "ȭ���ѱ���")
	{
		player.PlayerDmageSet(player.GetATK() + FeatherATk);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "�ڿ�������")
	{
		player.SetMaxHealth(player.GetMaxHealth() + NatureHealth);
		player.PlayerHealing(1000);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "��ȥ�ָӴ�")
	{
		player.SetMaxHealth(player.GetMaxHealth() + SoulHealth);
		player.PlayerHealing(1000);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "â���ѹ�������")
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
	if (type == "����")
	{
		BattleList.push_back(item);
		return;
	}
	else if (type == "����ǰ")
	{
		InventoryList.push_back(item);
		return;
	}
	else if (type == "�Ҹ�ǰ")
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

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

void Inventory::BossReward(Actor* Boss)
{
	if (Boss->GetName()=="�丣���")
	{
		InventoryList.push_back("ȭ���� ����");
		ConsumablesList.push_back("ȭ���� ����");
	}
	else if (Boss->GetName() == "���̷���")
	{
		InventoryList.push_back("���� ����");
		ConsumablesList.push_back("�ڿ��� ����");
	}
	else if (Boss->GetName() == "������ �׷�")
	{
		InventoryList.push_back("���ܿ� ����");
		ConsumablesList.push_back("��ȥ �ָӴ�");
	}
	else if (Boss->GetName() == "������ ��Ӵ� ��ũ")
	{
		InventoryList.push_back("�Ƿ� ���� ����");
		ConsumablesList.push_back("â���� ���� ����");
	}
}

void Inventory::UseItem(string Choise, Player& player)
{
	if (Choise == "�ν˱�")
	{
		player.PlayerDmageSet(player.GetATK()+10);
		player.PlayerDmagetaken(20);
		printf("������ %d.\n", player.GetATK());
		DeleteConsumablesItem(Choise);
	}
	return;
}

void Inventory::PushItem(string item)
{
	InventoryList.push_back(item);
	return;
}

bool Inventory::FindItem(string item)
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

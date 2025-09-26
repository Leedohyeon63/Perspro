#pragma once
#include "Player.h"
#include "Inventory.h"
#include <vector>
//플레이어 인벤토리 관련 작업 관리하는 클래스
struct Item
{//아이템 관련 구조체 이름, 타입, 설명, 가격, 재구매 여부
    std::string Name;
    std::string Type;
    std::string Description;
    int Price;
    bool CantReSell;

};

class Shop
{
public:
    Shop();
    bool NotVisit = true;
    void OpenShop(Player* player, Inventory* inventory);
    void LoadItem(int stage, Inventory* playerInventory);
private:
    void DisplayItems();
    void SellItem(int itemIndex, Player* player, Inventory* inventory);
    std::vector<Item> ForSaleItems;
};


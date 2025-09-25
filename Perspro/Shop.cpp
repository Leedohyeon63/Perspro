#include "Shop.h"
#include <iostream>
Shop::Shop()
{
    ForSaleItems.push_back({ "회복물약","전투", "체력을 50 회복합니다.", 20});
}

void Shop::OpenShop(Player* player, Inventory* inventory)
{
    int Choice = 0;
    while (true)
    {
        system("cls");
        printf("==================상점==================\n");
        printf("소지금: %d Gold\n\n", player->GetGold());
        DisplayItems();
        printf("========================================\n");
        printf("구매할 아이템의 번호를 입력하세요 (나가려면 0번): ");
        std::cin >> Choice;

        if (Choice == 0) {
            break;
        }
        if (Choice > 0 && Choice <= ForSaleItems.size()) {
            SellItem(Choice - 1, player, inventory);
        }
        else {
            printf("잘못된 번호입니다.\n");
        }
        system("pause");
    }
}

void Shop::DisplayItems()
{
    for (int i = 0; i < ForSaleItems.size(); ++i)
    {
        const auto& Item = ForSaleItems[i];
        printf("%d. %s, %d 원\n : %s\n", i + 1, Item.Name.c_str(), Item.Price, Item.Description.c_str());
    }
}

void Shop::SellItem(int itemIndex, Player* player, Inventory* inventory)
{
    const Item& ItemBuy = ForSaleItems[itemIndex];

    if (player->GetGold() >= ItemBuy.Price)
    {
        player->PlayerGetMoney(-ItemBuy.Price);
        inventory->PushItem(ItemBuy.Name.c_str(), ItemBuy.Type); 
        printf("\n%s을(를) 구매했습니다..\n", ItemBuy.Name.c_str());
    }
    else
    {
        printf("\n골드가 부족합니다..\n");
    }
}

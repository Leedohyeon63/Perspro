#include "Shop.h"
#include <iostream>
Shop::Shop()
{
    ForSaleItems.push_back({ "ȸ������","����", "ü���� 50 ȸ���մϴ�.", 20});
}

void Shop::OpenShop(Player* player, Inventory* inventory)
{
    int Choice = 0;
    while (true)
    {
        system("cls");
        printf("==================����==================\n");
        printf("������: %d Gold\n\n", player->GetGold());
        DisplayItems();
        printf("========================================\n");
        printf("������ �������� ��ȣ�� �Է��ϼ��� (�������� 0��): ");
        std::cin >> Choice;

        if (Choice == 0) {
            break;
        }
        if (Choice > 0 && Choice <= ForSaleItems.size()) {
            SellItem(Choice - 1, player, inventory);
        }
        else {
            printf("�߸��� ��ȣ�Դϴ�.\n");
        }
        system("pause");
    }
}

void Shop::DisplayItems()
{
    for (int i = 0; i < ForSaleItems.size(); ++i)
    {
        const auto& Item = ForSaleItems[i];
        printf("%d. %s, %d ��\n : %s\n", i + 1, Item.Name.c_str(), Item.Price, Item.Description.c_str());
    }
}

void Shop::SellItem(int itemIndex, Player* player, Inventory* inventory)
{
    const Item& ItemBuy = ForSaleItems[itemIndex];

    if (player->GetGold() >= ItemBuy.Price)
    {
        player->PlayerGetMoney(-ItemBuy.Price);
        inventory->PushItem(ItemBuy.Name.c_str(), ItemBuy.Type); 
        printf("\n%s��(��) �����߽��ϴ�..\n", ItemBuy.Name.c_str());
    }
    else
    {
        printf("\n��尡 �����մϴ�..\n");
    }
}

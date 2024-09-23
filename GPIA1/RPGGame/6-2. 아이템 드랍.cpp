#include <iostream>
#include "6-2. Item.h"
#include "6-4. Inventory.h"
using namespace std;

Item* DropItem()
{
    if (rand() % 2 == 0)
    {
        Weapon* weapon = new Weapon;
        return weapon;
    }
    else
    {
        Armor* armor = new Armor;
        return armor;
    }
}

int main()
{
    srand((unsigned)time(0));

    for (int i = 0; i < 100; ++i)
    {
        Item* item = DropItem();
        item->PrintInfo();

        // 몬스터 처지
        if (Inventory::GetInstance()->AddItem(item))
        {
            cout << "Added Item to Inven" << endl;
        }
        else
        {
            cout << "Failed to add Item" << endl;
            delete item;
        }

        // PK로 인해 랜덤으로 일부 아이템 드랍
        for (int i = 0; i < 20; ++i)
        {
            int randIndex = rand() % MAX_SLOT;
            Item* item = Inventory::GetInstance()->GetItemAtSlot(randIndex);

            if (item && Inventory::GetInstance()->RemoveItem(item))
                cout << "Remove Item" << endl;
        }

       /* ItemType itemType = item->GetItemType();

        if (itemType == IT_Weapon)
        {
            Weapon* weapon = (Weapon*)item;
            weapon->GetDamage();
        }
        else if (itemType == IT_Armor)
        {
            Armor* armor = (Armor*)item;
            armor->GetDefence();
        }*/

        // delete item
    }
}
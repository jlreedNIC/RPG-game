#include "item.h"
#include "weapon.h"
#include "armor.h"
#include <iostream>

void test(Itemclass &item);

int main()
{
    std::cout << "hello\n";

    Itemclass item;
    Weapon myWeapon;
    Armor myArmor;

    myWeapon.create("sword", 5, 20);
    myArmor.create("hard leather", 15, 30);

    test(item);

    std::cout << myWeapon.print();
    std::cout << myArmor.print();
    std::cout << item.print();

    return 0;
}

void test(Itemclass &item)
{
    item.create("emerald", "gem", 5, 20);
}
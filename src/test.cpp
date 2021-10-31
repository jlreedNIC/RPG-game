#include "item.h"
#include "weapon.h"
#include "armor.h"
#include "monster.h"
#include "player.h"
#include <iostream>

void test(Itemclass &item);

int main()
{
    Itemclass item;
    Weapon myWeapon;
    Armor myArmor;
    Monster myMonster;
    Player myPlayer;

    myMonster.create("goblin", "fighter", 3);
    std::cout << myMonster.printStats();
    myPlayer.create("elf", "wizard", 5);
    std::cout << myPlayer.printStats();

    myPlayer.addQuest("Help people in the mine.");
    myPlayer.addQuest("Get the key from the mayor.");
    std::cout << myPlayer.printQuests();

    myPlayer.addWeapon("sword", 5, 15);
    myPlayer.addWeapon("staff", 5, 13);

    myPlayer.setEquipped(0);

    std::cout << myPlayer.printInventory();

    return 0;
}

void test(Itemclass &item)
{
    item.create("emerald", "gem", 5, 20);
}
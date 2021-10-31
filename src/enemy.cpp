#include "enemy.h"
#include <iostream>
using namespace std;

void Enemy::create(string monster, int temp_level)
{
    level = temp_level;
    if(monster == "orc" || monster == "Orc" || monster == "ORC")
    {
        health = 40;
        max_health = 40;
        name = "orc";
    }
    if(monster == "gnome" || monster == "Gnome" || monster == "GNOME")
    {
        health = 70;
        max_health = 70;
        name = "gnome";
    }
    if(monster == "goblin" || monster == "Goblin" || monster == "GOBLIN")
    {
        health = 100;
        max_health = 100;
        name = "goblin";
    }
    stats();
}

void Enemy::stats()
{
    experience = level*5;
    attack = level*2;
    defense = (level-1)/1.5;
    gold = 10 + (level*2);
}

void Enemy::print()
{
    cout << "The level " << level << " " << name << " has:" << endl;
    cout << " Health: " << health << "/" << max_health << endl;
}

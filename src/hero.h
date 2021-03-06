#ifndef HERO_H
#define HERO_H

#include "enemy.h"
#include "armor.h"
#include "weapon.h"
#include <fstream>
using namespace std;

class Hero
{
    public:
        string name, gender, race, trade;
        int level;
        int experience;
        int gold;
        int health, max_health;
        int strength, constitution, magicstat;
        int magic, magic_experience, damage[5];
        string spell[5];
        Weapon weapon[5];
        Armor armor[5];
        Itemclass item[9];
        string equipped_weapon, equipped_armor;
        int equipped_attack, equipped_defense, equipped_proficiency, equipped_prof_level;
        string quest[3];
        string quest_check;
        string save_point;

        char city[25][30];
        string cityname;

        int x, y;
        int mine_room;
        char map[21][37];
        int time;

        Hero();
        void save();
        void print_inventory();
        void print_quests();
        void print();
        void statprint();
        void statupdate();
        void quest_update(string);

        void mine();
        void map_mine();
        void map_city();
        void move(string, string);
        void set_map(string);

        void heal(string);
        void equip();
        void shop_weapon();
        void shop_armor();
        void shop_item();
        void shop_upgrade();
        void location(string);
        int train(string, string);
        void tavern(string);

        void picture_fight(int, int, string, int, int);
        void fight_player();

    protected:
    private:
};

#endif
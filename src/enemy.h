#ifndef ENEMY_H
#define ENEMY_H

#include "item.h"
using namespace std;


class Enemy
{
    public:
        int health, max_health;
        int level, experience;
        int gold;
        int attack, defense;
        string name;

        void stats();
        void create(string, int);
        void print();
    protected:

    private:
};

#endif // ENEMY_H

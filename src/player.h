/**
 * @file player.h
 * @author Jordan Reed (jlreed@students.nic.edu)
 * @date 10-29-21
 * @brief Definition file for Player class. Inherited from Monster class.
 *        Intended for the hero.
 * 
 */

/*
 * Need to keep working on this class. Keep separating out functions from hero.cpp
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "monster.h"
#include "weapon.h"
#include <vector>

class Player : public Monster
{
    public:
        Player();
        ~Player();

        std::string printInventory();       // output all inventory items
        std::string printQuests();
        virtual std::string printStats();

        void addQuest(const std::string &quest);
        void addWeapon(const std::string &weapon, const int &attack, const int &price);

        void setEquipped(const int &num);
    
    private:
        std::string name;
        std::string gender;

        int strength;           // attack
        int constitution;       // health
        int intelligence;       // magicstat

        std::vector<Weapon> weapons;
        Weapon *equippedWeapon;

        std::vector<std::string> quests;    // to hold quests
};

#endif
/**
 * @file monster.h
 * @author Jordan Reed (jlreed@students.nic.edu)
 * @date 10-29-21
 * @brief Definition file for Monster class. Base class.
 *        For monsters. From original enemy class.
 * 
 */

#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <sstream>

class Monster
{
    public:
        Monster();
        ~Monster();

        void create(const std::string& race, const std::string& cClass, const int& level);
        virtual std::string printStats();

        // what setters and getters do I really need to implement?

    protected:
        std::string race;
        std::string cClass;

        int health, maxHealth;
        int gold;
        int attack, defense; 
        int level, experience;
};

#endif
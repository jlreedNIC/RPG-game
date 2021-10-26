#ifndef NPC_H
#define NPC_H

#include <string>

class Npc
{
    public:
        Npc();
        Npc(const std::string &name, const std::string &race);
        ~Npc();

        // setters
        void setName(const std::string &name);
        void setRace(const std::string &race);
        void setClass(const std::string &charClass);
        void setHealth(const int &health);

        // getters
        std::string getName();
        std::string getRace();
        std::string getClass();
        int getHealth();

    protected:
        std::string name;
        std::string race;           // character race (eg elf, dwarf, human, etc)
        std::string charClass;      // character class (eg wizard, fighter, archer, etc)

        int health, maxHealth;
};

#endif
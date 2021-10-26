#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon : public Itemclass
{
    public:
        Weapon();
        ~Weapon();

        virtual std::string print();
        virtual void create(const std::string &name, const int &attack, const int &price);
        virtual void load(std::fstream &ifs);
        virtual void save(std::fstream &ofs);

        int getAttack();
        void setAttack(const int &attack);

        int getProficiency();
        int getProfLevel();
        void setProficiency(const int &proficiency);
        void setProfLevel(const int &profLevel);

        void incAttack(const int &attack);
        void incProficiency(const int &prof);

    private:
        int proficiency;
        int profLevel;
};

#endif
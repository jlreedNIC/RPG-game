/**
 * @file armor.h
 * @author Jordan Reed (jlreed@students.nic.edu)
 * @date 10-25-21
 * @brief Definition files for Armor class. Inherited from Itemclass.
 *        Designed for 'pieces of armor'.
 * 
 */

#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"

class Armor : public Itemclass
{
    public:
        Armor();        // constructor
        ~Armor();       // destructor

        virtual std::string print();                    // outputs information for armor into a string
        virtual void create(const std::string &name, const int &defence, const int &price);     // creates armor with given parameters
        virtual void load(std::fstream &ifs);           // loads armor info from file
        virtual void save(std::fstream &ofs);           // saves armor info to file

        int getDefence();                               // returns defence value
        void setDefence(const int &defence);            // sets defence value

        int getProficiency();                           // gets proficiency info
        int getProfLevel();                             // gets proficiency level
        void setProficiency(const int &proficiency);    // sets proficiency value
        void setProfLevel(const int &profLevel);        // sets proficiency level

        void incDefense(const int &defence);            // increases defence value by given parameter
        void incProficiency(const int &prof);           // increases proficiency value by given parameter

    private:
        int proficiency;
        int profLevel;
};

#endif
/**
 * @file item.h
 * @author Jordan Reed (jlreed@students.nic.edu)
 * @date 10-25-21
 * @brief Definition file for Itemclass. 
 * 
 */

#ifndef ITEM_H
#define ITEM_H

#include <iomanip>
// #include <iostream> // not needed for itemclass
// #include <fstream> // not needed for itemclass
// #include <cstdlib> // not needed for itemclass
#include <sstream>
#include <fstream>

/*
 * Notes: separate into parent Item class and child Weapon, Armor, Item, Potion, etc
 *
 */

class Itemclass
{
    public:
        Itemclass();                            // constructor
        ~Itemclass();                           // destructor

        virtual void create(const std::string &itemName, const std::string &itemType, const int &itemVar, const int &worth);
        void destroy();                         // resets item to none and 0
        void set_sellprice();                   // sets the sell price relative to price
        virtual std::string print();            // outputs item info into a string
        virtual void load(std::fstream &ifs);   // loads item info from file
        virtual void save(std::fstream &ofs);   // saves item info to file

        // getters
        int getPrice();                         // returns price value
        int getSellPrice();                     // returns sell price value
        std::string getName();                  // returns name of item
        std::string getType();                  // returns type of item
        // int getAttack();
        // int getDefence();
        // int getProficiency();
        // int getProfLevel();
        int getHealing();                       // returns healing value

        // setters
        void setPrice(const int &newPrice);             // sets price of item
        void setSellPrice(const int &newSellPrice);     // sets sell price of item
        void setName(const std::string &newName);       // sets name of item
        void setType(const std::string &newType);       // sets type of item
        // void setAttack(const int &newAttack);
        // void setDefence(const int &newDefence);
        // void setProficiency(const int &newProf);
        // void setProfLevel(const int &newPLevel);
        void setHealing(const int &newHealing);         // sets healing value

    protected:
        int price;              // purchase price
        int sell_price;         // sell price
        std::string name;       // name of item
        std::string type;       // type of item
        // int attack;
        // int defence;
        // int proficiency;
        // int prof_level;
        int healing;            // amount item can be used to heal

        int attribute;          // attribute attached to item (eg attack or defence or healing)

    private:
        
        
};

#endif
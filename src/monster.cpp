#include "monster.h"

Monster::Monster()
{
    race = "";
    cClass = "";

    health = maxHealth = 0;
    gold = 0;
    attack = defense = 0;
    level = experience = 0;
}

Monster::~Monster()
{

}

void Monster::create(const std::string& race, const std::string& cClass, const int& level)
{
    this->race = race;
    this->cClass = cClass;
    this->level = level;
}

std::string Monster::printStats()
{
    std::stringstream ostr;

    ostr << "The level " << level << " " << race << " has:\n";
    ostr << " Health: " << health << "/" << maxHealth << "\n";

    return ostr.str();
}
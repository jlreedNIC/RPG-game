#include "player.h"

Player::Player() : Monster()
{
    name = "";
    gender = "";
    strength = constitution = intelligence = 0;
    equippedWeapon = NULL;
}

Player::~Player()
{

}

// fix format
std::string Player::printInventory()
{
    std::stringstream ostr;

    ostr << std::setw(13) << "Weapon" << std::setw(8) << "Attack" << std::setw(13) << "Proficiency" << std::setw(13) << "Proficiency" << std::setw(7) << "Price\n";
    ostr << std::setw(32) << "Points" << std::setw(12) << "Level\n";
    ostr << std::setw(13) << "------" << std::setw(8) << "------" << std::setw(13) << "-----------" << std::setw(13) << "-----------" << std::setw(7) << "-----\n";
    
    int size = weapons.size();
    for(int i=0; i < size; i++)
    {
        ostr << weapons[i].print();
    }

    ostr << "\n\nEquipped Weapon:\n";
    ostr << equippedWeapon->print();

    return ostr.str();
}

std::string Player::printQuests()
{
    std::stringstream ostr;

    int size = quests.size();
    for(int i=0; i<size; i++)
    {
        ostr << quests[i] << "\n";
    }

    return ostr.str();
}

std::string Player::printStats()
{
    std::stringstream ostr;

    ostr << "\n" << name << " the " << race << " " << cClass << " has: \n";
    ostr << " Health:        " << health << "/" << maxHealth << "\n";
    ostr << " Level:         " << level << "\n";
    ostr << " Experience:    " << experience << "\n";
    ostr << " Gold:          " << gold << "\n\n";

    return ostr.str();
}

void Player::addQuest(const std::string &quest)
{
    quests.push_back(quest);
}

void Player::addWeapon(const std::string &weapon, const int &attack, const int &price)
{
    Weapon temp(weapon, attack, price);
    weapons.push_back(temp);
}

void Player::setEquipped(const int &num)
{
    if(weapons.size() == 0) exit(1);

    if(num-1 >= weapons.size() || num-1 < 0) exit(1);

    equippedWeapon = &weapons[num-1];
}
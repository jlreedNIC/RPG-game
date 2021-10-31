#include "weapon.h"

Weapon::Weapon() : Itemclass()
{
    type = "weapon";
    proficiency = 0;
    profLevel = 0;
}

Weapon::Weapon(const std::string &name, const int &attack, const int &price) : Itemclass()
{
    type = "weapon";
    proficiency = 0;
    profLevel = 0;

    this->name = name;
    attribute = attack;
    this->price = price;
    set_sellprice();
}

Weapon::~Weapon()
{

}

std::string Weapon::print()
{
    std::stringstream ostr;
    
    ostr << std::setw(13) << name << std::setw(6) << attribute << std::setw(11) << proficiency;
    ostr << std::setw(13) << profLevel << std::setw(9) << sell_price << "g\n";

    return ostr.str();
}

void Weapon::create(const std::string &name, const int &attack, const int &price)
{
    this->name = name;
    attribute = attack;
    this->price = price;
    set_sellprice();

}

void Weapon::load(std::fstream &ifs)
{
    ifs >> type >> name >> attribute >> proficiency >> profLevel >> price >> sell_price;
}

void Weapon::save(std::fstream &ofs)
{
    ofs << type << " " << name << " " << attribute << " " << proficiency << " " << profLevel << " " << price << " " << sell_price << "\n";
}

int Weapon::getAttack()
{
    return attribute;
}

void Weapon::setAttack(const int &attack)
{
    attribute = attack;
}

int Weapon::getProficiency()
{
    return proficiency;
}

int Weapon::getProfLevel()
{
    return profLevel;
}

void Weapon::setProficiency(const int &proficiency)
{
    this->proficiency = proficiency;
}

void Weapon::setProfLevel(const int &profLevel)
{
    this->profLevel = profLevel;
}

void Weapon::incAttack(const int &attack)
{
    attribute += attack;
}

void Weapon::incProficiency(const int &prof)
{
    proficiency += prof;
}
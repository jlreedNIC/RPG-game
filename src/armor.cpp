#include "armor.h"

Armor::Armor() : Itemclass()
{
    type = "armor";
    proficiency = 0;
    profLevel = 0;
}

Armor::~Armor()
{

}

std::string Armor::print()
{
    std::stringstream ostr;

    ostr << std::setw(13) << name << std::setw(6) << attribute << std::setw(7) << sell_price << "g\n";

    return ostr.str();
}

void Armor::create(const std::string &name, const int &defense, const int &price)
{
    this->name = name;
    this->price = price;
    attribute = defense;   
}

void Armor::load(std::fstream &ifs)
{
    ifs >> type >> name >> attribute >> proficiency >> profLevel >> price >> sell_price;
}

void Armor::save(std::fstream &ofs)
{
    ofs << type << " " << name << " " << attribute << " " << proficiency << " " << profLevel << " " << price << " " << sell_price << "\n";
}

int Armor::getdefense()
{
    return attribute;
}

void Armor::setdefense(const int &defense)
{
    attribute = defense;
}

int Armor::getProficiency()
{
    return proficiency;
}

int Armor::getProfLevel()
{
    return profLevel;
}

void Armor::setProficiency(const int &proficiency)
{
    this->proficiency = proficiency;
}

void Armor::setProfLevel(const int &profLevel)
{
    this->profLevel = profLevel;
}

void Armor::incDefense(const int &defense)
{
    attribute += defense;
}

void Armor::incProficiency(const int &prof)
{
    proficiency += prof;
}
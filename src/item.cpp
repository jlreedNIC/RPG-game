#include "item.h"

Itemclass::Itemclass()
{
    name = "";
    type = "item";
    price = 0;
    sell_price = 0;
    healing = 0;

    attribute = 0;
}

Itemclass::~Itemclass()
{
    // destructor
}

void Itemclass::create(const std::string &itemName, const std::string &itemType, const int &itemVar, const int &worth)
{
    name = itemName;
    type = itemType;
    price = worth;
    set_sellprice();

    if(type == "food")
    {
        healing = itemVar;
    }
}

void Itemclass::destroy()
{
    if(type == "gem") type = "item";
    name = "none";
    healing = 0;
    price = 0;
    sell_price = 0;
}

void Itemclass::set_sellprice()
{
    if(price <= 10) sell_price = price - 1;
    else if(price <= 20) sell_price = price - 5;
    else if(price <= 50) sell_price = price - 15;
    else if(price > 50) sell_price = price - (price*.05);
}

std::string Itemclass::print()
{
    std::stringstream ostr;

    if(type == "gem" || type == "food" || type == "item")
        ostr << std::setw(13) << name << std::setw(4) << sell_price << "g" << std::setw(8) << healing << "\n";

    return ostr.str();
}

void Itemclass::load(std::fstream &ifs)
{
    ifs >> type >> name >> price >> sell_price >> healing;
}

void Itemclass::save(std::fstream &ofs)
{
    ofs << type << " " << name << " " << price << " " << sell_price << " " << healing << "\n";
}

// getters and setters

int Itemclass::getPrice()
{
    return price;
}

int Itemclass::getSellPrice()
{
    return sell_price;
}

std::string Itemclass::getName()
{
    return name;
}

std::string Itemclass::getType()
{
    return type;
}

int Itemclass::getHealing()
{
    return healing;
}

void Itemclass::setPrice(const int &newPrice)
{
    price = newPrice;
}

void Itemclass::setSellPrice(const int &newSellPrice)
{
    sell_price = newSellPrice;
}

void Itemclass::setName(const std::string &newName)
{
    name = newName;
}

void Itemclass::setType(const std::string &newType)
{
    type = newType;
}

void Itemclass::setHealing(const int &newHealing)
{
    healing = newHealing;
}
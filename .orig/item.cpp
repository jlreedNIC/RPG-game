#include "item.h"

void Itemclass::create(string item_name, int item_variable, int worth)
{
    name = item_name;
    price = worth;
    set_sellprice();

    if(name == "dagger" || name == "sword" || name == "staff" || name == "bow")
    {
        type = "weapon";
        attack = item_variable;
        defence = 0;
        proficiency = 0;
        prof_level = 0;
        healing = 0;
    }
    else if(name == "leather" || name == "hard_leather" || name == "steel" || name == "clothes")
    {
        type = "armor";
        attack = 0;
        defence = item_variable;
        proficiency = 0;
        prof_level = 0;
        healing = 0;
    }
    else if(name == "ruby" || name == "sapphire" || name == "emerald" || name == "diamond")
    {
        type = "gem";
        attack = 0;
        defence = 0;
        proficiency = 0;
        prof_level = 0;
        healing = 0;
    }
    else if(name == "food" || name == "roast" || name == "chicken")
    {
        type = "food";
        attack = 0;
        defence = 0;
        proficiency = 0;
        prof_level = 0;
        healing = item_variable;
    }
    else if(name == "none")
    {
        type = "none";
        attack = 0;
        defence = 0;
        proficiency = 0;
        prof_level = 0;
        healing = 0;
    }
}

void Itemclass::destroy()
{
    if(type == "gem") type = "item";
    name = "none";
    attack = 0;
    defence = 0;
    proficiency = 0;
    prof_level = 0;
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

void Itemclass::print()
{
    if(type == "weapon")
        cout << setw(13) << name << setw(6) << attack << setw(11) << proficiency << setw(13) << prof_level << setw(9) << sell_price << "g" << endl;
    else if(type == "armor")
        cout << setw(13) << name << setw(6) << defence << setw(7) << sell_price << "g" << endl;
    else if(type == "gem" || type == "food" || type == "item")
        cout << setw(13) << name << setw(4) << sell_price << "g" << setw(8) << healing << endl;
}

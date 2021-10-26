#include "hero.h"
#include <iostream>
using namespace std;


Hero::Hero()
{
    string answer;
    int i, j, choice = 0;
    char choice2, choice3;

    do
    {
       cout << " (1) New file \n (2) Old file \n";
       cin >> choice2;
       switch(choice2)
       {
            case '1':
                cout << "What will your character's name be?" << endl;
                cin >> name;

                do
                {
                    cout << "Are you a boy or a girl?" << endl;
                    cout << " (1) Boy \n (2) Girl \n";
                    cin >> choice3;
                    switch(choice3)
                    {
                        case '1':
                            gender = "boy";
                            break;
                        case '2':
                            gender = "girl";
                            break;
                        default:
                            choice3 = '0';
                            cout << "Please choose a correct choice." << endl;
                            break;
                    }
                }while(choice3 == '0');

                do
                {
                    cout << "\nWhat is your profession?" << endl;
                    cout << " (1) Warrior \n (2) Wizard \n (3) Rogue \n (4) Archer" << endl;
                    cin >> choice3;
                    switch(choice3)
                    {
                        case '1':
                                trade = "warrior";
                                weapon[0].create("sword", 3, 7);
                                equipped_weapon = weapon[0].name;
                                equipped_attack = weapon[0].attack;
                                strength = 5;
                                gold = 30;
                                magicstat = 3;
                                break;
                        case '2':
                                trade = "wizard";
                                weapon[0].create("staff", 3, 7);
                                equipped_weapon = weapon[0].name;
                                equipped_attack = weapon[0].attack;
                                strength = 3;
                                gold = 30;
                                magicstat = 5;
                                break;
                        case '3':
                                trade = "rogue";
                                weapon[0].create("dagger", 3, 7);
                                equipped_weapon = weapon[0].name;
                                equipped_attack = weapon[0].attack;
                                strength = 2;
                                gold = 40;
                                magicstat = 3;
                                break;
                        case '4':
                                trade = "archer";
                                weapon[0].create("bow", 3, 7);
                                equipped_weapon = weapon[0].name;
                                equipped_attack = weapon[0].attack;
                                strength = 3;
                                gold = 30;
                                magicstat = 3;
                                break;
                        default:
                                cout << "Please choose again" << endl;
                                choice3 = '0';
                    }
                }while(choice3 == '0');

                do
                {
                    cout << "\nTo which race do you belong?" << endl;
                    cout << " (1) Human \n (2) Elf \n (3) Dwarf " << endl;
                    cin >> choice3;
                    switch(choice3)
                    {
                        case '1':
                            race = "human";
                            health = 100;
                            max_health = 100;
                            constitution = 4;
                            break;
                        case '2':
                            race = "elf";
                            health = 90;
                            max_health = 90;
                            constitution = 3;
                            strength -= 2;
                            magicstat += 2;;
                            break;
                        case '3':
                            race = "dwarf";
                            health = 110;
                            max_health = 110;
                            constitution = 5;
                            strength += 2;
                            magicstat -= 2;
                            break;
                        default:
                            cout << "Please choose a race again:" << endl;
                            choice3 = '0';
                            break;
                    }
                }while(choice3 == '0');

                cityname = "Argon";
                save_point = "Argon";
                level = 0;
                experience = 0;
                quest_check = "not_finished";

                equipped_proficiency = 20;
                equipped_prof_level = 0;
                weapon[0].proficiency = 20;

                armor[0].create("clothes", 1, 5);

                for(i=0; i<5; i++)
                {
                    if(i != 0)
                    {
                        weapon[i].create("none", 0, 0);
                        armor[i].create("none", 0, 0);
                        weapon[i].type = "weapon";
                        armor[i].type = "armor";
                    }

                    spell[i] = "none";
                    damage[i] = magicstat;
                }
                for(i=0; i<9; i++)
                {
                    item[i].create("none", 0, 0);
                    item[i].type = "item";
                }

                quest[0] = "Save_the_citizens_of_Argon_from_the_monsters_in_the_mine";
                quest[1] = "none";
                quest[2] = "none";

                equipped_weapon = weapon[0].name;
                equipped_attack = weapon[0].attack;
                equipped_proficiency = weapon[0].proficiency;
                equipped_prof_level = weapon[0].prof_level;
                equipped_armor = armor[0].name;
                equipped_defence = armor[0].defence;

                magic = 0;
                magic_experience = 0;
                spell[0] = "fire";
                damage[0] = 2 + magicstat;

                time = 1;
                x = 5;
                y = 0;
                mine_room = 1;

                set_map("mine");
                set_map("Argon");

                if(race == "human") cout << "As a child of the human world, you were accustomed to the way life ran in your small village. ";
                if(race == "dwarf") cout << "As a young dwarf, you were accustomed to the ways of your people, to the ways of the mountains. ";
                if(race == "elf") cout << "As a young elf, you grew up learning to give to the forest, learning the life force of every living thing around you. ";

                cout << "But you could see the hurt that evil has caused, not only among your people, but among the other ";
                cout << "races. You decided to join a group dedicated to keeping the realm of Fainyse out of evil's influence. ";
                cout << "As a new recruit, this group sent you on a beginner's mission. The little town of Argon was having ";
                cout << "an issue with some errant monsters in their mine. So you set off, determined to prove your worth. " << endl;
                break;
            case '2':
                cout << "What is your character's name?" << endl;
                cin >> name;
                ifstream ifs;
                ifs.open(name.c_str());
                if(ifs.fail())
                {
                    cout << "\nerror getting file" << endl;
                    exit(0);
                }

                ifs >> save_point >> name >> gender >> race >> trade >> health >> max_health >> level >> experience >> gold;
                ifs >> strength >> constitution >> magicstat;
                ifs >> equipped_weapon >> equipped_attack >> equipped_proficiency >> equipped_prof_level >> equipped_armor >> equipped_defence;
                for(i=0; i<5; i++)
                    ifs >> weapon[i].type >> weapon[i].name >> weapon[i].attack >> weapon[i].proficiency >> weapon[i].prof_level >> weapon[i].defence >> weapon[i].price >> weapon[i].sell_price >> weapon[i].healing;
                for(i=0; i<5; i++)
                    ifs >> armor[i].type >> armor[i].name >> armor[i].defence >> armor[i].attack >> armor[i].proficiency >> armor[i].prof_level >> armor[i].price >> armor[i].sell_price >> armor[i].healing;
                ifs >> magic >> magic_experience;
                for(i=0; i<5; i++)
                    ifs >> spell[i] >> damage[i];
                for(i=0; i<9; i++)
                    ifs >> item[i].type >> item[i].name >> item[i].price >> item[i].sell_price >> item[i].healing >> item[i].defence >> item[i].attack >> item[i].proficiency >> item[i].prof_level;
                ifs >> cityname;
                ifs >> quest[0] >> quest[1] >> quest[2] >> quest_check;
                ifs >> time >> x >> y >> mine_room;
                for(j=0; j<37; j++)
                    for(i=0; i<21; i++)
                        ifs >> map[i][j];
                for(j=0; j<30; j++)
                    for(i=0; i<25; i++)
                        ifs >> city[i][j];
                ifs.close();

                for(i=0; i<21; i++)
                    for(j=0; j<137; j++)
                        if(map[i][j] == '*') map[i][j] = ' ';
                for(i=0; i<25; i++)
                    for(j=0; j<30; j++)
                        if(city[i][j] == '*') city[i][j] = ' ';
                break;
       }
    }while(choice2 != '1' && choice2 != '2');
}

void Hero::save()
{
    int i, j;

    for(i=0; i<21; i++)
        for(j=0; j<37; j++)
            if(map[i][j] == ' ') map[i][j] = '*';
    for(i=0; i<25; i++)
        for(j=0; j<30; j++)
            if(city[i][j] == ' ') city[i][j] = '*';

    cout << "\nSaving..." << endl;
    ofstream ofs;
    ofs.open(name.c_str());
    ofs << save_point << endl << name << endl << gender << endl << race << endl << trade << endl << health << " " << max_health << endl << level << endl << experience << endl << gold << endl << endl;
    ofs << strength << endl << constitution << endl << magicstat << endl << endl;
    ofs << equipped_weapon << " " << equipped_attack << " " << equipped_proficiency << " " << equipped_prof_level << endl << equipped_armor << " " << equipped_defence << endl << endl;
    for(i=0; i<5; i++)
        ofs << weapon[i].type << " " << weapon[i].name << " " << weapon[i].attack << " " << weapon[i].proficiency << " " << weapon[i].prof_level << " " << weapon[i].defence << " " << weapon[i].price << " " << weapon[i].sell_price << " " << weapon[i].healing << endl;
    ofs << endl;
    for(i=0; i<5; i++)
        ofs << armor[i].type << " " << armor[i].name << " " << armor[i].defence << " " << armor[i].attack << " " << armor[i].proficiency << " " << armor[i].prof_level << " " << armor[i].price << " " << armor[i].sell_price << " " << armor[i].healing << endl;
    ofs << endl;
    ofs << magic << endl << magic_experience << endl;
    for(i=0; i<5; i++)
        ofs << spell[i] << " " << damage[i] << endl;
    ofs << endl;
    for(i=0; i<9; i++)
        ofs << item[i].type << " " << item[i].name << " " << item[i].price << " " << item[i].sell_price << " " << item[i].healing << " " << item[i].defence << " " << item[i].attack << " " << item[i].proficiency << " " << item[i].prof_level << endl;
    ofs << endl << cityname << endl;
    ofs << quest[0] << endl << quest[1] << endl << quest[2] << endl << quest_check << endl << endl;
    ofs << time << endl << x << endl << y << endl << endl << mine_room << endl;
    for(j=0; j<37; j++)
    {
        for(i=0; i<21; i++)
            ofs << map[i][j] << " ";
        ofs << endl;
    }
    for(j=0; j<30; j++)
    {
        for(i=0; i<25; i++)
            ofs << city[i][j] << " ";
        ofs << endl;
    }
    ofs.close();

    for(i=0; i<21; i++)
        for(j=0; j<37; j++)
            if(map[i][j] == '*') map[i][j] = ' ';
    for(i=0; i<25; i++)
        for(j=0; j<30; j++)
            if(city[i][j] == '*') city[i][j] = ' ';


}

void Hero::print_inventory()
{
    int choice, i;

    cout << endl << name << " has: " << endl;
    cout << "\nGold: " << gold << endl;
    cout << "Equipped: \n    " << equipped_weapon << endl << "    " << equipped_armor << endl;
    cout << "What else would you like to see?" << endl;
    do {cout << "\n (1) Items \n (2) Weapons \n (3) Armor \n (4) Spells \n (0) Exit" << endl;
        cin >> choice;
        switch(choice)
        {
            case 0:
                    break;
            case 1:
                    cout << setw(13) << "Item" << setw(6) << "Price" << setw(12) << "Hp restore" << endl;
                    cout << setw(13) << "----" << setw(6) << "-----" << setw(12) << "----------" << endl;
                    for(i=0; i<9; i++)
                        if(item[i].name != "none") item[i].print();
                    break;
            case 2:
                    cout << setw(13) << "Weapon" << setw(8) << "Attack" << setw(13) << "Proficiency" << setw(13) << "Proficiency" << setw(7) << "Price" << endl;
                    cout << setw(32) << "Points" << setw(12) << "Level" << endl;
                    cout << setw(13) << "------" << setw(8) << "------" << setw(13) << "-----------" << setw(13) << "-----------" << setw(7) << "-----" << endl;
                    for(i=0; i<5; i++)
                        if(weapon[i].name != "none") weapon[i].print();
                    break;
            case 3:
                    cout << setw(13) << "Armor" << setw(9) << "Defence" << setw(6) << "Price" << endl;
                    cout << setw(13) << "-----" << setw(9) << "-------" << setw(6) << "-----" << endl;
                    for(i=0; i<5; i++)
                        if(armor[i].name != "none") armor[i].print();
                    break;
            case 4:
                    cout << "Spells:";
                    for(i=0; i<5; i++)
                        if(spell[i] != "none") cout << setw(9) << spell[i] << setw(4) << damage[i] << " damage" << endl;
                    break;
            default:
                    cout << "Select another choice." << endl;
                    break;
        }
      } while(choice != 0);
}

void Hero::print_quests()
{
    int i;

    cout << "\nYou currently have the following quests:" << endl;
    for(i=0; i<3; i++)
    {
        if(quest[i] != "none") cout << quest[i] << endl;
    }
    cout << endl;
}

void Hero::heal(string place)
{
    char choice;
    int i;

    if(place == "healer")
    {
        cout << "You walk into the small healers tent. There is an old woman sitting in a rocking chair towards the back. ";
        cout << "With a raspy voice, she addresses you. 'Hello young " << race << ". Do you need me to heal you?'" << endl;
        do
        {
            cout << " (1) Be healed for 8 coins \n (2) Leave\n";
            cin >> choice;
            switch(choice)
            {
                case '1':
                    health = max_health;
                    gold -= 8;
                    print();
                    break;
                case '2':
                    break;
                default:
                    cout << "Speak up, young one. These old ears can't hear you." <<endl;
                    choice = '0';
                    break;
            }
        }while(choice == '0');
        cout << "Come again!" << endl;
    }
    else if(place == "self")
        {
            cout << "\nIt costs 10 proficiency points (not levels) to heal yourself. Do you want to heal yourself?" << endl;
            do
            {
                cout << " (1) Heal yourself for 10 proficiency points \n (2) Don't heal \n";
                cin >> choice;
                switch(choice)
                {
                    case '1':
                        health = max_health;
                        equipped_proficiency -= 10;
                        for(i=0; i<5; i++)
                            if(equipped_weapon == weapon[i].name) weapon[i].proficiency = equipped_proficiency;
                        print();
                        break;
                    case '2':
                        break;
                    default:
                        cout << "Please choose again" << endl;
                        choice = '0';
                        break;
                }
            }while(choice == '0');
         }
}

void Hero::print()
{
    cout << endl << name << " has:" << endl;
    cout << " Health:        " << health << "/" << max_health << endl;
    cout << " Level:         " << level << endl;
    cout << " Experience:    " << experience << endl;
    cout << " Gold:          " << gold << endl << endl;
}

void Hero::equip()
{
    int i, choice, choice2 = 1;
    string answer, answer2;
    char choice3;

    cout << "\nThis is what you currently have equipped:" << endl;
    cout << " Armor:    " << equipped_armor << endl;
    cout << " Weapon:   " << equipped_weapon << endl;
    cout << "\nWould you like to change what you have equipped?" << endl;
    do
    {
        cout << " (1) Change what you have equipped \n (2) Don't change equipment \n";
        cin >> choice3;
        switch(choice3)
        {
            case '1':
                cout << "What would you like to change?" << endl;
                cout << " (1) Armor \n (2) Weapons \n (0) Exit \n";
                cin >> choice;
                switch(choice)
                {
                    case 0:
                        break;
                    case 1:
                        cout << "This is the armor you have: " << endl;
                        for(i=0; i<3; i++)
                        {
                            if(armor[i].name != "none") cout << setw(13) << armor[i].name << setw(4) << armor[i].defence << endl;
                        }
                        cin >> answer2;
                        do
                        {
                            for(i=0; i<3; i++)
                            {
                                if(answer2 == armor[i].name)
                                {
                                    choice2 = 0;
                                    break;
                                }
                                else if(answer2 != armor[i].name) choice2 = 1;
                            }
                            if(choice2 == 1)
                            {
                                cout << "You don't have " << answer2 << " armor. Please choose again." << endl;
                                cin >> answer2;
                            }
                        } while(choice2 == 1);
                        for(i=0; i<3; i++)
                        {
                            if(armor[i].name == answer2)
                            {
                                equipped_armor = armor[i].name;
                                equipped_defence = armor[i].defence;
                            }
                        }
                        if(equipped_armor != answer2) cout << "You don't have " << answer2 << " armor!" << endl;
                        else if(equipped_armor == answer2) cout << "You have equipped your " << answer2 << " armor." << endl;
                        break;
                    case 2:
                        cout << "These are the weapons you have you have: " << endl;
                        for(i=0; i<3; i++)
                        {
                            if(weapon[i].name != "none") cout << setw(11) << weapon[i].name << setw(4) << weapon[i].attack << " attack" << setw(3) << weapon[i].prof_level << " proficiency" << endl;
                        }
                        cin >> answer2;
                        do
                        {
                            for(i=0; i<3; i++)
                            {
                                if(answer2 == weapon[i].name)
                                {
                                    choice2 = 0;
                                    break;
                                }
                                else if(answer2 != weapon[i].name) choice2 = 1;
                            }
                            if(choice2 == 1)
                            {
                                cout << "You don't have a " << answer2 << ". Please choose again." << endl;
                                cin >> answer2;
                            }
                        }while(choice2 == 1);
                        for(i=0; i<3; i++)
                        {
                            if(weapon[i].name == answer2)
                            {
                                equipped_weapon = weapon[i].name;
                                equipped_attack = weapon[i].attack;
                                equipped_proficiency = weapon[i].proficiency;
                            }
                        }
                        if(equipped_weapon != answer2) cout << "You don't have a " << answer2 << "!" << endl;
                        else if(equipped_weapon == answer2) cout << "You have equipped your " << answer2 << "." << endl;
                }
                break;
            case '2':
                break;
            default:
                cout << "Invalid choice" << endl;
                choice3 = '0';
                break;
        }
    }while(choice3 == '0');
}

void Hero::statprint()
{
    cout << endl << name << ": " << race << " " << trade << endl << endl;
    cout << setw(15) << "Health:" << "    " << health << "/" << max_health << endl;
    cout << setw(15) << "Level:" << "    " << level << endl;
    cout << setw(15) << "Experience:" << "    " << experience << endl;
    cout << setw(15) << "Attack:" << "    " << equipped_attack << endl;
    cout << setw(15) << "Proficiency:" << "    " << equipped_prof_level << endl;
    if(equipped_armor != "none") cout << setw(15) << "Defence:" << "    " << equipped_defence << endl;
    cout << setw(15) << "Magic:" << "    " << magic << endl;
    cout << endl << setw(15) << "Strength:" << "    " << strength << endl;
    cout << setw(15) << "Constitution:" << "    " << constitution << endl;
    cout << setw(15) << "Magic Stat:" << "    " << magicstat << endl;
}
void Hero::statupdate()
{
    double temp_level, temp_prof_level, prof_difference, difference = 0, i, temp_const, const_diff, temp_magic, magic_diff, temp_damage[5];
    int choice, equipped_magic;


    temp_level = level;
    level = experience/100;
    difference = level - temp_level;
    temp_prof_level = equipped_prof_level;

    for(i=0; i<5; i++)
    {
        weapon[i].prof_level = weapon[i].proficiency/130;
        if(equipped_weapon == weapon[i].name)
        {
            equipped_prof_level = weapon[i].prof_level;
            equipped_proficiency = weapon[i].proficiency;
        }
    }
    prof_difference = equipped_prof_level - temp_prof_level;

    temp_magic = magic;
    magic = magic_experience/100;
    magic_diff = magic - temp_magic;
    for(i=0; i<5; i++)
        temp_damage[i] = damage[i] - magicstat;

    temp_const = constitution;

    if(level/2 == (level+1)/2 && difference >= 1)
    do
    {
        cout << "You can add one point to one of the stats below:" << endl;
        cout << " (1)" << setw(13) << "Strength" << "   " << strength << endl;
        cout << " (2)" << setw(13) << "Constitution" << "   " << constitution << endl;
        cout << " (3)" << setw(13) << "Magic" << "   " << magicstat << endl;
        cin >> choice;
        if(choice == 1) strength += 1;
        else if(choice == 2) constitution += 1;
        else if(choice == 3) magicstat += 1;
        else cout << "Please choose a different stat" << endl;
    }while(choice != 1 && choice != 2 && choice != 3);

    const_diff = constitution - temp_const;
    temp_const = constitution/2.0;
    if(constitution/2 == (constitution+1)/2 && const_diff >= 1) max_health += 5;

    for(i=0; i<5; i++)
    {
        if(weapon[i].name != "none" && level/2 == (level+1)/2 && difference >= 1) weapon[i].attack += difference;
        if(equipped_weapon == weapon[i].name)
        {
            equipped_attack = strength + weapon[i].attack;
            weapon[i].proficiency = equipped_proficiency;
            weapon[i].prof_level = equipped_prof_level;
        }
    }
    equipped_attack += prof_difference;
    for(i=0; i<5; i++)
        if(equipped_weapon == weapon[i].name) weapon[i].attack = equipped_attack - strength;

    for(i=0; i<5; i++)
        if(spell[i] != "none") damage[i] = temp_damage[i] + magicstat;
    for(i=0; i<5; i++)
        if(spell[i] != "none" && magic/2 == (magic+1)/2 && magic_diff >= 1) damage[i] += magic_diff;

    if(difference == 1)
    {
        cout << "\n **********************************" << endl;
        cout << "*    *      *        *      *      *" << endl;
        cout << "*   *          *        *      *   *" << endl;
        cout << "*     You have gained a level!     *" << endl;
        cout << "*    *                  *        * *" << endl;
        cout << "*  *            *               *  *" << endl;
        cout << " **********************************" << endl;
    }
    else if(difference > 1)
    {
        cout << " **********************************" << endl;
        cout << "*    *      *        *      *      *" << endl;
        cout << "*   *          *        *      *   *" << endl;
        cout << "*    You have gained " << difference << " levels!     *" << endl;
        cout << "*    *                  *        * *" << endl;
        cout << "*  *            *               *  *" << endl;
        cout << " **********************************" << endl;
        cout << "You've gained " << difference << " levels!" << endl;
    }
}

void Hero::shop_weapon()
{
    int i, choice, choice2;
    string item_check, answer;

    if(cityname == "Argon")
    {
        cout << "You step into the tent inside the marketplace. Inside is a huge burly man selling weapons." << endl;
        cout << "'Hello there! Welcome to my weapons shop." << endl;
        do
        {
            cout << "What can I do for you today?'" << endl;
            cout << " (1) Buying \n (2) Selling \n (0) Exit" << endl;
            cin >> choice;
            switch(choice)
            {
                case 0:
                        cout << "'Thanks for stopping by!'" << endl;
                        break;
                case 1:
                        //buying
                        cout << " (1) Sword   10 gold  2 attack\n (2) Dagger  10 gold  2 attack\n (3) Bow     10 gold  2 attack\n (4) Staff   10 gold  2 attack\n\n (0) Exit" << endl;
                        cin >> choice2;
                        switch(choice2)
                        {
                            case 0:
                                    break;
                            case 1:
                                    //sword
                                    if(gold >= 10)
                                    {
                                        for(i=0; i<5; i++)
                                            if(weapon[i].name == "sword")
                                            {
                                                item_check = "false";
                                                break;
                                            }
                                        if(item_check == "false") cout << "You already have this weapon!" << endl;
                                        else
                                        {
                                            for(i=0; i<5; i++)
                                                if(weapon[i].name == "none")
                                                {
                                                    item_check = "true";
                                                    break;
                                                }
                                            if(weapon[i].name == "none")
                                            {
                                                weapon[i].create("sword", 2, 10);
                                                gold -= weapon[i].price;
                                                cout << "You have bought a sword!" << endl;
                                                item_check = "true";
                                                break;
                                            }
                                        }
                                    }
                                    else cout << "You don't have enough gold!" << endl;
                                    break;
                            case 2:
                                    //dagger
                                    if(gold >= 10)
                                    {
                                        for(i=0; i<5; i++)
                                            if(weapon[i].name == "dagger")
                                            {
                                                item_check = "false";
                                                break;
                                            }
                                        if(item_check == "false") cout << "You already have this weapon!" << endl;
                                        else
                                        {
                                            for(i=0; i<5; i++)
                                                if(weapon[i].name == "none")
                                                {
                                                    item_check = "true";
                                                    break;
                                                }
                                            if(weapon[i].name == "none")
                                            {
                                                weapon[i].create("dagger", 2, 10);
                                                gold -= weapon[i].price;
                                                cout << "You have bought a dagger!" << endl;
                                                item_check = "true";
                                                break;
                                            }
                                        }
                                    }
                                    else cout << "You don't have enough gold!" << endl;
                                    break;
                            case 3:
                                    //bow
                                    if(gold >= 10)
                                    {
                                        for(i=0; i<5; i++)
                                            if(weapon[i].name == "bow")
                                            {
                                                item_check = "false";
                                                break;
                                            }
                                        if(item_check == "false") cout << "You already have this weapon!" << endl;
                                        else
                                        {
                                            for(i=0; i<5; i++)
                                                if(weapon[i].name == "none")
                                                {
                                                    item_check = "true";
                                                    break;
                                                }
                                            if(weapon[i].name == "none")
                                            {
                                                weapon[i].create("bow", 2, 10);
                                                gold -= weapon[i].price;
                                                cout << "You have bought a bow!" << endl;
                                                item_check = "true";
                                                break;
                                            }
                                        }
                                    }
                                    else cout << "You don't have enough gold!" << endl;
                                    break;
                            case 4:
                                    //staff
                                    if(gold >= 10)
                                    {
                                        for(i=0; i<5; i++)
                                            if(weapon[i].name == "staff")
                                            {
                                                item_check = "false";
                                                break;
                                            }
                                        if(item_check == "false") cout << "You already have this weapon!" << endl;
                                        else
                                        {
                                            for(i=0; i<5; i++)
                                                if(weapon[i].name == "none")
                                                {
                                                    item_check = "true";
                                                    break;
                                                }
                                            if(weapon[i].name == "none")
                                            {
                                                weapon[i].create("staff", 2, 10);
                                                gold -= weapon[i].price;
                                                cout << "You have bought a staff!" << endl;
                                                item_check = "true";
                                                break;
                                            }
                                        }
                                    }
                                    else cout << "You don't have enough gold!" << endl;
                                    break;
                            default:
                                    cout << "Invalid choice" << endl;
                                    break;
                        }
                        break;
                case 2:
                        //selling
                        cout << "\nYou have the following weapons:" << endl;
                        for(i=0; i<5; i++)
                            if(weapon[i].name != "none") cout << " " << weapon[i].name << " " << weapon[i].sell_price << " gold" << endl;
                        cout << "\nWhich do you want to sell?" << endl;
                        cin >> answer;
                        for(i=0; i<5; i++)
                            if(weapon[i].name == answer && answer != "none")
                            {
                                item_check = "true";
                                break;
                            }
                            else item_check = "false";
                        if(equipped_weapon != answer && item_check == "true")
                        {
                            gold += weapon[i].sell_price;
                            cout << "You have sold your " << weapon[i].name << " for " << weapon[i].sell_price << " gold." << endl;

                            weapon[i].destroy();
                            break;
                        }
                        else if(equipped_weapon == answer) cout << "You can't sell something you have equipped." << endl;
                        if(item_check == "false") cout << "You don't have this weapon!" << endl;
                        break;
                default:
                        cout << "'Eh? What did you say?'" << endl;
                        break;
            }
        } while(choice != 0);
    }
}

void Hero::shop_armor()
{
    int i, choice, choice2;
    string item_check, answer;

    if(cityname == "Argon")
    {
        cout << "You walk inside the armor tent to find a woman leaning against one of the poles." << endl;
        cout << "'Don't touch what you don't intend to buy. I don't tolerate people messing with my armor.'" << endl;
        do
        {
            cout << "What do you want to do?" << endl;
            cout << " (1) Buy \n (2) Sell \n (0) Exit" << endl;
            cin >> choice;
            switch(choice)
            {
                case 0:
                        cout << "'Don't let the tent flap hit you on your way out.'" << endl;
                        break;
                case 1:
                        //buying
                        cout << "\nThis is what I currently have: " << endl;
                        cout << " (1) Leather armor           10 gold  5 defence\n (2) Hardened leather armor  20 gold  10 defence \n (3) Steel armor             50 gold  17 defence \n\n (0) Exit" << endl;
                        cin >> choice2;
                        switch(choice2)
                        {
                            case 0:
                                    break;
                            case 1:
                                    //leather
                                    if(gold >= 10)
                                    {
                                        for(i=0; i<5; i++)
                                            if(armor[i].name == "leather")
                                            {
                                                item_check = "false";
                                                break;
                                            }
                                        if(item_check == "false") cout << "You already have this armor!" << endl;
                                        else
                                        {
                                            for(i=0; i<5; i++)
                                                if(armor[i].name == "none")
                                                {
                                                    item_check = "true";
                                                    break;
                                                }
                                            if(armor[i].name == "none")
                                            {
                                                armor[i].create("leather", 5, 10);
                                                gold -= armor[i].price;
                                                cout << "You have bought leather armor." << endl;
                                                item_check = "true";
                                                break;
                                            }
                                        }
                                    }
                                    else cout << "'Don't try to steal from me you half-wit!" << endl;
                                    break;
                            case 2:
                                    //hard leather
                                    if(gold >= 20)
                                    {
                                        for(i=0; i<5; i++)
                                            if(armor[i].name == "hard_leather")
                                            {
                                                item_check = "false";
                                                break;
                                            }
                                        if(item_check == "false") cout << "You already have this armor!" << endl;
                                        else
                                        {
                                            for(i=0; i<5; i++)
                                                if(armor[i].name == "none")
                                                {
                                                    item_check = "true";
                                                    break;
                                                }
                                            if(armor[i].name == "none")
                                            {
                                                armor[i].create("hard_leather", 10, 20);
                                                gold -= armor[i].price;
                                                cout << "You have bought hardened leather armor." << endl;
                                                item_check = "true";
                                                break;
                                            }
                                        }
                                    }
                                    else cout << "'Don't try to steal from me you half-wit!" << endl;
                                    break;
                            case 3:
                                    //steel
                                    if(gold >= 50)
                                    {
                                        for(i=0; i<5; i++)
                                            if(armor[i].name == "steel")
                                            {
                                                item_check = "false";
                                                break;
                                            }
                                        if(item_check == "false") cout << "You already have this armor!" << endl;
                                        else
                                        {
                                            for(i=0; i<5; i++)
                                                if(armor[i].name == "none")
                                                {
                                                    item_check = "true";
                                                    break;
                                                }
                                            if(armor[i].name == "none")
                                            {
                                                armor[i].create("steel", 17, 50);
                                                gold -= armor[i].price;
                                                cout << "You have bought steel armor." << endl;
                                                item_check = "true";
                                                break;
                                            }
                                        }
                                    }
                                    else cout << "'Don't try to steal from me you half-wit!" << endl;
                                    break;
                            default:
                                    cout << "Invalid choice" << endl;
                                    break;
                        }
                        break;
                case 2:
                        //selling
                        cout << "If you must..." << endl;
                        cout << "\nYou have the following armor:" << endl;
                        for(i=0; i<5; i++)
                            if(armor[i].name != "none") cout << " " << armor[i].name << " " << armor[i].sell_price << " gold" << endl;
                        cout << "\nWhich do you want to sell?" << endl;
                        cin >> answer;
                        for(i=0; i<5; i++)
                            if(armor[i].name == answer && answer != "none")
                            {
                                item_check = "true";
                                break;
                            }
                            else item_check = "false";
                        if(equipped_armor != answer && item_check == "true")
                        {
                            gold += armor[i].sell_price;
                            cout << "You have sold your " << armor[i].name << " for " << armor[i].sell_price << " gold." << endl;
                            armor[i].destroy();
                            break;
                        }
                        else if(equipped_armor == answer) cout << "You can't sell something you have equipped." << endl;
                        if(item_check == "false") cout << "You don't have this armor." << endl;
                        break;
                default:
                        cout << "'If you don't speak up, I can't understand what you're saying." << endl;
                        break;
            }
        }while(choice !=0);
    }
}

void Hero::shop_item()
{
    int i, choice, choice2, choice3;
    string item_check, answer;

    cout << "You step into the brightly colored tent. Inside there are an assortment of gems as well as food. You attention rests on the young woman in the corner." << endl;
    cout << "'Hi there! Welcome to my items shop!'" << endl;
    do
    {
        cout << "'What can I help you with today?'" << endl;
        cout << " (1) Buying \n (2) Selling \n (0) Exit" << endl;
        cin >> choice;
        switch(choice)
        {
            case 0:
                    cout << "'Thanks for stopping by! Come back soon!" << endl;
                    break;
            case 1:
                    //buying
                    cout << "What would you like to buy?" << endl;
                    do
                    {
                        cout << " (1) Food \n (2) Jewels \n (0) Exit" << endl;
                        cin >> choice2;
                        switch(choice2)
                        {
                            case 1:
                                    cout << "Food will cost you 10 gold. It can be used to heal 10 hit points. Do you want to buy some?" << endl;
                                    cin >> answer;
                                    if(answer == "yes" || answer == "Yes")
                                    {
                                        if(gold >= 10)
                                        {
                                            for(i=0; i<9; i++)
                                                if(item[i].name == "none")
                                                {
                                                    item_check = "true";
                                                    break;
                                                }
                                                else item_check = "false";
                                            if(item_check == "true")
                                            {
                                                item[i].create("food", 10, 10);
                                                gold -= item[i].price;
                                                break;
                                            }
                                            else if(item_check == "false") cout << "'You don't quite have enough room in your inventory. Come back when you've made room." << endl;
                                        }
                                        else cout << "Honey, I still need to be paid somehow." << endl;
                                    }
                                    break;
                            case 2:
                                    cout << "Gems can be used for many things, but most adventurers use them to upgrade their weapons. I currently have the following gems:" << endl;
                                    cout << " (1) Ruby \n (2) Emerald \n (3) Sapphire \n (4) Diamond \n (0) Exit" << endl;
                                    cin >> choice3;
                                    switch(choice3)
                                    {
                                        case 1:
                                                cout << "A ruby costs 35 gold. It can be used in the upgrade shop (not currently available). Would you like to buy it?" << endl;
                                                cin >> answer;
                                                if(answer == "yes" || answer == "Yes")
                                                {
                                                    if(gold >= 35)
                                                    {
                                                        for(i=0; i<9; i++)
                                                            if(item[i].name == "none")
                                                            {
                                                                item_check = "true";
                                                                break;
                                                            }
                                                            else item_check = "false";
                                                        if(item_check == "true")
                                                        {
                                                            item[i].create("ruby", 0, 35);
                                                            gold -= item[i].price;
                                                            cout << "You have bought a ruby." << endl;
                                                            break;
                                                        }
                                                        else if(item_check == "false") cout << "'You don't quite have enough room in your inventory. Come back when you've made room." << endl;
                                                    }
                                                    else cout << "Honey, I still need to be paid somehow." << endl;
                                                }
                                                break;
                                        case 2:
                                                cout << "An emerald costs 35 gold. It can be used in the upgrade shop (not currently available). Would you like to buy it?" << endl;
                                                cin >> answer;
                                                if(answer == "yes" || answer == "Yes")
                                                {
                                                    if(gold >= 35)
                                                    {
                                                        for(i=0; i<9; i++)
                                                            if(item[i].name == "none")
                                                            {
                                                                item_check = "true";
                                                                break;
                                                            }
                                                            else item_check = "false";
                                                        if(item_check == "true")
                                                        {
                                                            item[i].create("emerald", 0, 35);
                                                            gold -= item[i].price;
                                                            cout << "You have bought an emerald." << endl;
                                                            break;
                                                        }
                                                        else if(item_check == "false") cout << "'You don't quite have enough room in your inventory. Come back when you've made room." << endl;
                                                    }
                                                    else cout << "Honey, I still need to be paid somehow." << endl;
                                                }
                                                break;
                                        case 3:
                                                cout << "A sapphire costs 35 gold. It can be used in the upgrade shop (not currently available). Would you like to buy it?" << endl;
                                                cin >> answer;
                                                if(answer == "yes" || answer == "Yes")
                                                {
                                                    if(gold >= 35)
                                                    {
                                                        for(i=0; i<9; i++)
                                                            if(item[i].name == "none")
                                                            {
                                                                item_check = "true";
                                                                break;
                                                            }
                                                            else item_check = "false";
                                                        if(item_check == "true")
                                                            {
                                                                item[i].create("sapphire", 0, 35);
                                                                gold -= item[i].price;
                                                                cout << "You have bought a sapphire." << endl;
                                                                break;
                                                            }
                                                        else if(item_check == "false") cout << "'You don't quite have enough room in your inventory. Come back when you've made room." << endl;
                                                    }
                                                    else cout << "Honey, I still need to be paid somehow." << endl;
                                                }
                                                break;
                                        case 4:
                                                cout << "A diamond costs 45 gold. It can be used in the upgrade shop (not currently available). Would you like to buy it?" << endl;
                                                cin >> answer;
                                                if(answer == "yes" || answer == "Yes")
                                                {
                                                    if(gold >= 45)
                                                    {
                                                        for(i=0; i<9; i++)
                                                            if(item[i].name == "none")
                                                            {
                                                                item_check = "true";
                                                                break;
                                                            }


                                                            else item_check = "false";
                                                        if(item_check == "true")
                                                            {
                                                                item[i].create("diamond", 0, 45);
                                                                gold -= item[i].price;
                                                                cout << "You have bought a diamond." << endl;
                                                                break;
                                                            }
                                                        else if(item_check == "false") cout << "'You don't quite have enough room in your inventory. Come back when you've made room." << endl;
                                                    }
                                                    else cout << "Honey, I still need to be paid somehow." << endl;
                                                }
                                                break;
                                        default:
                                                cout << "Invalid choice" << endl;
                                                break;
                                    }
                                    break;
                            default:
                                    cout << "Sorry, I can't understand you." << endl;
                        }
                    }while(choice2 != 0);
                    break;
            case 2:
                    //selling
                    cout << "'I'd love to help you out!'" << endl;
                    cout << "\nYou have the following items:" << endl;
                    for(i=0; i<9; i++)
                        if(item[i].name != "none") cout << setw(14) << item[i].name << "  " << item[i].sell_price << " gold" << endl;
                    cout << "\nWhich do you want to sell?" << endl;
                    cin >> answer;
                    for(i=0; i<9; i++)
                        if(item[i].name == answer && answer != "none")
                        {
                            item_check = "true";
                            break;
                        }
                        else item_check = "false";
                    if(item_check == "true")
                    {
                        cout << "You have sold your " << item[i].name << " for " << item[i].sell_price << " gold." << endl;
                        gold += item[i].sell_price;
                        item[i].destroy();
                        break;
                    }
                    else cout << "'Maybe you're confused...Hon, you don't have this item." << endl;
                    break;
            default:
                    cout << "'Aw, you don't have to be shy around me. I'm not like Isana with her armor. I won't yell at you.'" << endl;
                    break;
        }
    }while(choice != 0);
}

void Hero::shop_upgrade()
{
    int choice, i, j;
    string answer, item_check;

    cout << "Hi there. Welcome to the upgrade shop. Here you can add different aspects to your weapons and make them stronger." << endl;
    cout << "A ruby will add 2 attack to a weapon. An emerald will add 3, while a sapphire will add 4 attack. A diamond will add 5 attack. Of course, for a small fee, we can boost up your proficiency as well." << endl;
    do
    {
        cout << "\nWhat would you like to do?" << endl;
        cout << " (1) Upgrade \n (2) Up proficiency \n\n (0) Exit" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                    cout << "\nWhich weapon would you like to upgrade?" << endl;
                    for(i=0; i<5; i++)
                        if(weapon[i].name != "none") cout << " " << weapon[i].name << "  " << weapon[i].attack << " attack" << endl;
                    cin >> answer;
                    for(i=0; i<5; i++)
                        if(answer == weapon[i].name)
                        {
                            item_check = "true";
                            break;
                        }
                        else item_check = "false";
                    if(item_check == "true")
                    {
                        cout << "\nWhat would you like to add to your weapon?" << endl;
                        for(j=0; j<9; j++)
                            if(item[j].name != "food" && item[j].name != "none") cout << " " << item[j].name << endl;
                        cin >> answer;
                        for(j=0; j<9; j++)
                            if(answer == item[j].name && answer != "none")
                            {
                                item_check = "true";
                                break;
                            }
                            else item_check = "false";
                        if(item_check == "true")
                        {
                            if(item[j].name == "ruby")
                            {
                                weapon[i].attack += 2;
                                item[j].destroy();
                                cout << "You have added a ruby to your " << weapon[i].name << "." << endl;
                                for(i=0; i<5; i++)
                                    if(weapon[i].name == equipped_weapon) equipped_attack = strength + weapon[i].attack;
                                statupdate();
                            }
                            else if(item[j].name == "emerald")
                            {
                                weapon[i].attack += 3;
                                item[j].destroy();
                                cout << "You have added an emerald to your " << weapon[i].name << "." << endl;
                                for(i=0; i<5; i++)
                                    if(weapon[i].name == equipped_weapon) equipped_attack = strength + weapon[i].attack;
                                statupdate();
                            }
                            else if(item[j].name == "sapphire")
                            {
                                weapon[i].attack += 4;
                                item[j].destroy();
                                cout << "You have added a sapphire to your " << weapon[i].name << "." << endl;
                                for(i=0; i<5; i++)
                                    if(weapon[i].name == equipped_weapon) equipped_attack = strength + weapon[i].attack;
                                statupdate();
                            }
                            else if(item[j].name == "diamond")
                            {
                                weapon[i].attack += 5;
                                item[j].destroy();
                                cout << "You have added a diamond to your " << weapon[i].name << "." << endl;
                                for(i=0; i<5; i++)
                                    if(weapon[i].name == equipped_weapon) equipped_attack = strength + weapon[i].attack;
                                statupdate();
                            }
                        }
                        else if(item_check == "false") cout << "You don't have that item!" << endl;
                    }
                    else if(item_check == "false") cout << "You don't have that weapon!" << endl;
                    break;
            case 2:
                    cout << "Which weapon would you like to be more proficient with?" << endl;
                    for(i=0; i<5; i++)
                        if(weapon[i].name != "none") cout << weapon[i].name << "  " << weapon[i].prof_level << " proficiency" << endl;
                    cin >> answer;
                    for(i=0; i<5; i++)
                        if(answer == weapon[i].name && answer != "none")
                        {
                            item_check = "true";
                            break;
                        }
                        else item_check = "false";
                    if(item_check == "true")
                    {
                        cout << "We can add 1 proficiency level for 150 gold to your " << weapon[i].name << ". Would you like to do it?" << endl;
                        cin >> answer;
                        if(answer == "yes" || answer == "Yes" || answer == "YES")
                        {
                            if(gold >= 150)
                            {
                                weapon[i].proficiency += 130;
                                gold -= 150;
                                cout << "You have added 1 proficiency level to your " << weapon[i].name << "." << endl;
                                for(i=0; i<5; i++)
                                    if(weapon[i].name == equipped_weapon) equipped_proficiency = weapon[i].proficiency;
                                statupdate();
                            }
                            else cout << "You don't have enough gold!" << endl;
                        }
                        else break;
                    }
                    else if(item_check == "false") cout << "You don't have that weapon!" << endl;
                    break;
            default:
                    break;
        }

    }while(choice != 0);

}

int Hero::train(string monster, string place)
{
    int choice, i, j, enemyattack1, check = 0, turn = 0;
    double temp_experience, temp_gold, temp_attack, temp_proficiency = 0, temp_magic_xp = 0;
    char acknowledge;
    string answer, choice2, item_check;

    Enemy enemy;

    if(place == "wild" && mine_room == 1)
        if(monster == "orc" || monster == "Orc")
            enemy.create(monster, 4);
        else if(monster == "gnome" || monster == "Gnome")
            enemy.create(monster, 6);
        else if(monster == "goblin" || monster == "Goblin")
            enemy.create(monster, 9);
    if(place == "arena")
        if(monster == "orc" || monster == "Orc")
            enemy.create(monster, 4);
        else if(monster == "gnome" || monster == "Gnome")
            enemy.create(monster, 7);
        else if(monster == "goblin" || monster == "Goblin")
            enemy.create(monster, 12);
    else
    {
        cout << "Error getting monster" << endl;
        check = 1;
    }

        temp_experience = (enemy.experience * .5) + rand()%5;
        temp_gold = (enemy.gold * .5) + rand()%5;
    if(check == 1) choice = 0;
    else do
    {
        cout << "\nWhat would you like to do? \n\n (1) Attack \n (2) Attack with magic \n (3) Heal \n (4) Open inventory \n (0) Run away " << endl;
        cin >> choice;
        switch(choice)
        {
            case 0:
                    cout << "You run away in fear from the " << enemy.name << "." << endl;
                    return 0;
                    break;
            case 1:
                    //attack
                    temp_attack = equipped_attack + (rand()%7) - enemy.defence;
                    if(temp_attack <0) temp_attack = 0;
                    enemyattack1 = enemy.attack + (rand()%5) - equipped_defence;
                    if(enemyattack1 < 0) enemyattack1 = 0;

                    cout << "\nYou swing your " << equipped_weapon << " at the " << enemy.name << ", dealing " << temp_attack << " damage." << endl;
                    enemy.health -= temp_attack;
                    cout << "The " << enemy.name << " lunges at you, dealing " << enemyattack1 << " damage." << endl;
                    picture_fight(temp_attack, enemyattack1, "fight", 0, 0);
                    health -= enemyattack1;

                    if(health <= 0) health = 0;
                    if(enemy.health <= 0) enemy.health = 0;
                    print();
                    enemy.print();
                    temp_proficiency += 1;
                    turn += 1;
                    break;
            case 2:
                    //magic
                    j = 4;
                    cout << "What spell would you like to use?" << endl;
                    for(i=0; i<5; i++)
                        if(spell[i] != "none") cout << setw(9) << spell[i] << "   " << damage[i] << endl;
                    cin >> answer;
                    if(answer == spell[j]) turn = 0;
                    else turn += 1;
                    for(j=0; j<5; j++)
                        if(answer == spell[j] && spell[j] != "none") break;
                    if(spell[j] != "none")
                    {
                        temp_attack = damage[j] + (rand()%5) - enemy.defence;
                        if(temp_attack <0) temp_attack = 1;
                        enemyattack1 = enemy.attack + (rand()%5) - equipped_defence;
                        if(enemyattack1 < 0) enemyattack1 = 0;

                        cout << name << " casts a " << spell[j] << " spell at the " << enemy.name << ", dealing " << temp_attack << " damage." << endl;
                        cout << "The " << enemy.name << " lunges at " << name << ", dealing " << enemyattack1 << " damage." << endl;
                        picture_fight(temp_attack, enemyattack1, "fight", 0, 0);
                        health -= enemyattack1;
                        enemy.health -= temp_attack;

                        if(health < 0) health = 0;
                        if(enemy.health < 0) enemy.health = 0;
                        print();
                        enemy.print();
                        temp_magic_xp += 1;
                    }
                    else cout << "You don't have that spell!" << endl;
                    break;
            case 3:
                    //heal
                    cout << "It costs an extra 5 proficieny points to heal yourself while in battle. Do you wish to continue?" << endl;
                    cin >> answer;
                    if(answer == "yes" || answer == "Yes")
                    {
                        heal("self");
                        equipped_proficiency -= 5;
                        for(i=0; i<5; i++)
                            if(equipped_weapon == weapon[i].name) weapon[i].proficiency = equipped_proficiency;
                    }
                    turn += 1;
                    break;
            case 4:
                    //inventory
                    cout << "Inventory: " << endl;
                    for(i=0; i<9; i++)
                    {

                        if(item[i].name != "none") cout << item[i].name << "  " << item[i].healing << " healing power" << endl;

                    }
                    cout << "What would you like to use?" << endl;
                    cin >> choice2;
                    if(choice2 == "food")
                    {
                        for(i=0; i<9; i++)
                        {
                            if(item[i].name == "food")
                            {
                                item_check = "true";
                                break;
                            }
                            else item_check = "false";
                        }
                        if(item_check == "true")
                        {
                            health += item[i].healing;
                            if(health >= max_health) health = max_health;
                            item[i].destroy();
                            break;
                        }
                        else if(item_check == "false") cout << "You don't have any food." << endl;
                    }
                    else if(choice2 == "roast")
                    {
                        for(i=0; i<9; i++)
                        {
                            if(item[i].name == "roast")
                            {
                                item_check = "true";
                                break;
                            }
                            else item_check = "false";
                        }
                        if(item_check == "true")
                        {
                            health += item[i].healing;
                            if(health >= max_health) health = max_health;
                            item[i].destroy();
                            break;
                        }
                        else if(item_check == "false") cout << "You don't have any roasts." << endl;
                    }
                    else if(choice2 == "chicken")
                    {
                        for(i=0; i<9; i++)
                        {
                            if(item[i].name == "chicken")
                            {
                                item_check = "true";
                                break;
                            }
                            else item_check = "false";
                        }
                        if(item_check == "true")
                        {
                            health += item[i].healing;
                            if(health >= max_health) health = max_health;
                            item[i].destroy();
                            break;
                        }
                        else if(item_check == "false") cout << "You don't have any chicken." << endl;
                    }
                    else cout << "Invalid choice" << endl;
                    turn += 1;
                    break;
            default:
                    cout << "Pick another option." << endl;
                    break;
        }
    } while(choice != 0 && health > 0 && enemy.health > 0);
        if(enemy.health <= 0)
                {
                 picture_fight(temp_attack, enemyattack1, "win", temp_gold, temp_experience);
                 cout << "You have defeated the " << enemy.name << "! ";
                 magic_experience += temp_magic_xp;
                 experience += temp_experience;
                 equipped_proficiency += temp_proficiency;
                 gold += temp_gold;
                 cout << "You've gained " << temp_experience << " experience and have scavenged " << temp_gold << " gold pieces from the corpse." << endl;
                 if(health <= 0) health = 1;

                 for(i=0; i<5; i++)
                    if(weapon[i].name == equipped_weapon) weapon[i].proficiency = equipped_proficiency;
                 cout << "Press any key to continue" << endl;
                 cin >> acknowledge;
                 return 1;
                }
        else if(health <= 0)
        {
            cout << "The " << enemy.name << " has killed you!" << endl;
            picture_fight(temp_attack, enemyattack1, "lose", 0, 0);

            for(i=0; i<5; i++)
                if(weapon[i].name == equipped_weapon) weapon[i].proficiency = equipped_proficiency;
            cout << "Press any key to continue" << endl;
            cin >> acknowledge;
            return 0;
        }
}

void Hero::quest_update(string place)
{
    if(cityname == "Argon" && place == "city" && quest_check != "finished") quest[0] = "Save_the_citizens_of_Argon_from_the_monsters_in_the_mine";
    else if(cityname == "Argon" && place == "city" && quest_check == "finished") quest[0] = "return_to_group";
    if(cityname == "Argon" && place == "mine" && quest_check == "not_finished")
    {
        quest[0] = "Reach_the_lowest_level_of_the_mine";
        quest_check = "not_finished";
    }
    else if(cityname == "Argon" && place == "mine" && quest_check == "level_finished")
    {
        quest[0] = "Kill_boss_of_mine";
        quest_check = "not_finished";
    }

}

void Hero::mine()
{
    int random_orc, choice, item_drop, i;
    string item_check, monster;
    save_point = "Argon_mine";

    cout << "Upon entering the mine, you see evidence of orc, gnomes and other creatures you cannot even fathom." << endl;
    if(time == 1)
    {
        quest[0] = "Reach_lowest_level_of_the_mine";
        map[3][7] = 'o';
        map[3][10] = 'o';
        map[9][6] = 'o';
        map[7][9] = 'o';
        map[12][11] = 'o';
        map[11][11] = 'o';
        map[11][12] = 'o';
        map[12][12] = 'T';
    }
    if(city[x][y] == 'X')
        city[x][y] = ' ';
    if(map[x][y] == 'X')
        map[x][y] = ' ';
    x = 12;
    y = 0;
    map[x][y] = 'X';
    do
    {
        cout << "What would you like to do?" << endl;
        cout << " (1)  Move up \n (2)  Move down \n (3)  Move left \n (4)  Move right \n\n (5)  Look at map \n (6)  Look for traps \n\n (7)  Open inventory \n (8)  Show stats \n (9)  Change what you have equipped \n (10) Look at current quests \n\n (0)  Exit the mine" << endl;
        cin >> choice;
        switch(choice)
        {
            case 0:

                    if(map[12][0] != 'X')
                    {
                        cout << "You cannot exit until you reach the entrance." << endl;
                        choice = 1;
                    }
                    save();
                    break;
            case 1:
                    //move up
                    move("up", "mine");
                    map_mine();
                    break;
            case 2:
                    //move down
                    move("down", "mine");
                    map_mine();
                    break;
            case 3:
                    //move left
                    move("left", "mine");
                    map_mine();
                    break;
            case 4:
                    //move right
                    move("right", "mine");
                    map_mine();
                    break;
            case 5:
                    //map
                    map_mine();
                    break;
            case 6:
                    //traps
                    cout << "You find no traps." << endl;
                    break;
            case 7:
                    //inventory
                    print_inventory();
                    break;
            case 8:
                    //stats
                    statprint();
                    break;
            case 9:
                    //equipped
                    equip();
                    break;
            case 10:
                    //quests
                    print_quests();
                    break;
            default:
                    cout << "Please choose again." << endl;
                    break;
        }
        random_orc = 1 + rand()%4;
        if(random_orc == 1)
        {
            if(choice == 0) break;
            cout << "An orc approaches you. He will not let you pass till you fight." << endl;
            if(train("orc", "wild"))
            {
                for(i=0; i<9; i++)
                    if(item[i].name == "none")
                    {
                        item_check = "true";
                        break;
                    }
                if(item_check == "true")
                {
                    item_drop = rand()%7;
                    if(item_drop == 0)
                    {
                        item[i].create("rusty_dagger", 0, 6);
                        cout << "You find a rusty dagger on the orc's corpse. Perhaps you can sell it at the shop." << endl;
                    }
                    if(item_drop == 1)
                    {
                        item[i].create("ruby", 0, 35);
                        cout << "A ruby clatters away from the corpse as it falls. It looks like it could be worth some gold." << endl;
                    }
                    if(item_drop == 2)
                    {
                        item[i].create("emerald", 0, 35);
                        cout << "An emerald falls away from the corpse as it collapses. Maybe you could add it to your weapon." << endl;
                    }
                    if(item_drop == 3)
                    {
                        item[i].create("sapphire", 0, 35);
                        cout << "A sapphire of a startling blue color catches your attention." << endl;
                    }
                    if(item_drop == 4)
                    {
                        item[i].create("diamond", 0, 45);
                        cout << "A diamond falls to the floor as you strike the last blow. It is definitely worth some gold." << endl;
                    }
                }
            }
            statupdate();
        }
    if(x == 5 && y == 0)
    {
        choice = 0;
        cout << "You have exited the mine." << endl;
    }
    if(health <= 0)
    {
        map[x][y] = ' ';
        x = 5;
        y = 0;
        map[x][y] = 'X';
    }
    }while(choice != 0 && health > 0);
}

void Hero::map_mine()
{
    int i, j;

    cout << "    ";
    for(j=0; j<37; j++)
    {
        for(i=0; i<21; i++)
        if(map[i][j] == 'o' || map[i][j] == 'b' || map[i][j] == 'a') cout << " ";
        else cout << map[i][j];
        cout << endl << "    ";
    }
    cout << endl;
}

void Hero::location(string place)
{
    int choice, choice2, i;
    string monster, item_check = "false";

    if(place == "Argon")
    {
        save_point = "Argon";
        if(city[x][y] == 'X')
            city[x][y] = ' ';
        if(map[x][y] == 'X')
            map[x][y] = ' ';
        x = 10;
        y = 0;
        city[x][y] = 'X';
        cityname = place;
        cout << "You walk into the city of Argon. It is slightly rundown. The streets have very few people out and about. They grab the items they need, and hurry to get back inside. The monsters of the mine have made this town very wary." << endl;
        do{
            cout << "\nWhat would you like to do?" << endl;
            cout << " (1) Move up \n (2) Move down \n (3) Move left \n (4) Move right \n\n (5) Look in your inventory \n (6) Show your stats \n (7) Look at your current quests \n (8) Equip items \n\n (0) Exit the town" << endl;
            cin >> choice;
            switch(choice)
            {
                case 0:
                        //save and quit
                        if(city[10][0] != 'X')
                        {
                            cout << "You cannot exit without reaching the entrance." << endl;
                            choice = 5;
                        }
                        save();
                        break;
                case 1:
                        //move up
                        move("up", "city");
                        break;
                case 2:
                        //move down
                        move("down", "city");
                        break;
                case 3:
                        //move left
                        move("left", "city");
                        break;
                case 4:
                        //move right
                        move("right", "city");
                        break;
                case 5:
                        //inventory
                        print_inventory();
                        break;
                case 6:
                        //stats
                        statprint();
                        break;
                case 7:
                        //quests
                        print_quests();
                        break;
                case 8:
                        //equip
                        equip();
                        break;
                default:
                        cout << "Invalid choice" << endl;
                        break;
            }
            map_city();
            statupdate();
        }while(choice != 0);
    }
}

void Hero::map_city()
{
    int i, j;
    system("cls");

    cout << "    ";
    for(j=0; j<30; j++)
    {
        for(i=0; i<25; i++)
            if(city[i][j] == '&' || city[i][j] == '[' || city[i][j] == '!') cout << " ";
            else cout << city[i][j];
        cout << endl << "    ";
    }
    cout << "             shops ^" << endl;
}

void Hero::picture_fight(int attack, int damage, string status, int gold, int temp_exp)
{
    char picture[20][20];
    int i, j;

    for(i=0; i<20; i++)
        for(j=0; j<20; j++)
            picture[i][j] = ' ';

    if(status == "fight")
    {
        //monster
        for(i=12; i<15; i++)
        {
            picture[i][1] = '#';
            picture[i][5] = '#';
        }
        for(j=2; j<5; j++)
        {
            picture[11][j] = '#';
            picture[15][j] = '#';
        }
        for(j=5; j<10; j++)
            picture[13][j] = '#';
        for(i=12; i<15; i++)
            picture[i][7] = '#';
        picture[15][8] = '#';
        picture[12][10] = '#';
        picture[12][11] = '#';
        picture[14][10] = '#';
        picture[15][11] = '#';
        picture[11][6] = '#';
        picture[12][2] = '*';
        picture[14][2] = '*';
        for(i=12; i<15; i++)
            picture[i][4] = '-';

        //self
        for(i=3; i<6; i++)
        {
            picture[i][5] = '#';
            picture[i][11] = '#';
        }
        for(j=7; j<10; j++)
        {
            picture[1][j] = '#';
            picture [7][j] = '#';
        }
        for(j=12; j<18; j++)
            picture[4][j] = '#';
        picture[3][14] = '#';
        picture[2][13] = '#';
        picture[5][14] = '#';
        picture[6][12] = '#';
        picture[6][13] = '#';
        picture[3][18] = '#';
        picture[2][19] = '#';
        picture[5][18] = '#';
        picture[5][19] = '#';
        picture[2][6] = '#';
        picture[2][10] = '#';
        picture[6][6] = '#';
        picture[6][10] = '#';

        picture[18][6] = ' ';
        picture[9][17] = ' ';

        if(damage > 0)
        {
            picture[9][16] = '|';
            picture[9][18] = '|';
            picture[8][16] = '\\';
            picture[8][17] = '-';
            picture[8][18] = '/';
            picture[10][16] = '/';
            picture[10][17] = '-';
            picture[10][18] = '\\';
        }

        picture[19][5] = '/';
        picture[19][6] = '-';
        picture[19][7] = '\\';
        picture[18][5] = '|';
        picture[18][7] = '|';
        picture[17][5] = '\\';
        picture[17][6] = '-';
        picture[17][7] = '/';

        cout << endl;
        for(j=0; j<20; j++)
        {
            for(i=0; i<20; i++)
                if(i == 18 && j == 6) cout << attack;
                else if(i == 9 && j == 17 && damage >= 0) cout << damage;
                else cout << picture[i][j];
            cout << endl;
        }
        cout << endl;
    }
    if(status == "win")
    {
        //self
        for(i=7; i<10; i++)
        {
            picture[i][0] = '#';
            picture[i][6] = '#';
        }
        for(j=2; j<5; j++)
        {
            picture[5][j] = '#';
            picture[11][j] = '#';
        }
        picture[6][1] = '#';
        picture[6][5] = '#';
        picture[10][1] = '#';
        picture[10][5] = '#';
        for(j=7; j<12; j++)
            picture[8][j] = '#';
        for(i=6; i<11; i++)
            picture[i][8] = '#';
        picture[5][7] = '#';
        picture[4][6] = '#';
        picture[11][7] = '#';
        picture[12][6] = '#';
        picture[9][12] = '#';
        picture[9][13] = '#';
        picture[7][12] = '#';
        picture[6][13] = '#';
        picture[7][2] = '^';
        picture[9][2] = '^';
        picture[6][4] = '\\';
        picture[7][4] = '_';
        picture[8][4] = '_';
        picture[9][4] = '_';
        picture[10][4] = '/';

        //dead monster
        for(i=1; i<4; i++)
        {
            picture[i][19] = '#';
            picture[i+3][18] = '#';
            picture[i+6][17] = '#';
        }
        picture[7][19] = '#';
        for(i=10; i<13; i++)
        {
            picture[i][15] = '#';
            picture[i][19] = '#';
        }
        for(j=16; j<19; j++)
        {
            picture[9][j] = '#';
            picture[13][j] = '#';
            picture[10][j] = '|';
        }
        picture[12][16] = 'X';
        picture[12][18] = 'X';

        cout << endl << name << " has won!" << endl;
        for(j=0; j<20; j++)
        {
            for(i=0; i<20; i++)
                if(i == 17 && j == 2) cout << "You've gained:";
                else if(i == 17 && j == 4) cout << gold << " gold";
                else if(i == 17 && j == 6) cout << temp_exp << " experience";
                else cout << picture[i][j];
            cout << endl;
        }
        cout << endl;
    }

    if(status == "lose")
    {
        for(i=4; i<17; i++)
            picture[i][19] = '#';
        for(j=3; j<9; j++)
        {
            picture[4][(2*j)+1] = 'o';
            picture[16][(2*j)+1] = 'o';
        }
        picture[5][5] = 'o';
        picture[7][3] = 'o';
        for(i=9; i<12; i++)
            picture[i][2] = 'o';
        picture[15][5] = 'o';
        picture[13][3] = 'o';

        picture[6][18] = '#';
        picture[6][17] = '#';
        picture[7][16] = '#';
        picture[8][15] = '#';
        picture[9][18] = '#';
        picture[11][18] = '#';
        picture[13][16] = '#';
        picture[14][17] = '#';
        picture[14][18] = '#';


        picture[6][8] = 'H';
        picture[7][8] = 'e';
        picture[8][8] = 'r';
        picture[9][8] = 'e';
        picture[11][8] = 'L';
        picture[12][8] = 'i';
        picture[13][8] = 'e';
        picture[14][8] = 's';


        cout << endl << name << " has died!" << endl;
        for(j=0; j<20; j++)
        {
            for(i=0; i<20; i++)
                if(i == 8 && j == 10) cout << name;
                else cout << picture[i][j];
            cout << endl;
        }
        cout << endl;
    }

}

void Hero::fight_player()
{
    Hero player2;
     player2temp_attack, player2temp_proficiency, player2temp_experience, player2temp_gold, player2temp_magic_xp = 0, player2turn = 0;
    int temp_attack, temp_proficiency, temp_experience, temp_gold, temp_magic_xp = 0, turn = 0;
    int choice, choice2, i, j, k;
    string answer, item_check;

    player2temp_experience = player2.experience * .03;
    temp_experience = experience * .03;

    player2temp_gold = player2.gold * .1;
    temp_gold = gold * .1;

    cout << name << " is now fighting against " << player2.name << endl;

    do
    {
        if(choice == 2 && turn < 3)
            player2.health -= 1;
        if(choice2 == 2 && player2turn < 3)
            health -= 1;
        do
        {
            cout << endl << name << ", what would you like to do?" << endl;
            cout << "\n (1) Attack \n (2) Attack with magic \n (3) Heal \n (4) Open inventory \n (5) Re-equip \n\n (0) Run away" << endl;
            cin >> choice;
            if(choice > 5) cout << "Please pick another choice" << endl;
            if(choice == 1)
            {
                temp_attack = equipped_attack + (rand()%7) - player2.equipped_defence;
                if(temp_attack < 0) temp_attack = 0;

                cout << endl << name << " lunges at " << player2.name << ", dealing " << temp_attack << " damage." << endl;
                player2.health -= temp_attack;
                picture_fight(temp_attack, -1, "fight", 0, 0);

                statupdate();
                print();
                temp_proficiency += 1;
                cout << endl;
                player2.statupdate();
                player2.print();
            }
            if(choice == 2)
            {
                cout << "What spell would you like to use?" << endl;
                for(i=0; i<5; i++)
                    if(spell[i] != "none") cout << setw(9) << spell[i] << "   " << damage[i] << endl;
                cin >> answer;
                if(answer == spell[k]) turn += 1;
                else turn = 0;
                for(k=0; k<5; k++)
                    if(answer == spell[k]) break;

                temp_attack = damage[k] + (rand()%5) - player2.equipped_defence;

                if(temp_attack <0) temp_attack = 1;

                cout << name << " casts a " << spell[k] << " spell at " << player2.name << ", dealing " << temp_attack << " damage." << endl;
                picture_fight(temp_attack, -1, "fight", 0, 0);
                player2.health -= temp_attack;

                if(health < 0) health = 0;
                if(player2.health < 0) player2.health = 0;
                print();
                player2.print();
                statupdate();
                player2.statupdate();
                temp_magic_xp += 1;
            }
        }while(choice > 5);

        if(choice == 0)
        {
            cout << name << " has run away from " << player2.name << "!" << endl;
            break;
        }
        do
        {
            cout << endl << player2.name << ", what would you like to do?" << endl;
            cout << "\n (1) Attack \n (2) Attack with magic \n (3) Heal \n (4) Open inventory \n (5) Re-equip \n\n (0) Run away" << endl;
            cin >> choice2;
            if(choice2 > 5) cout << "Please pick another choice" << endl;
            if(choice2 == 1)
            {
                player2temp_attack = player2.equipped_attack + (rand()%7) - equipped_defence;
                if(player2temp_attack < 0) player2temp_attack = 0;

                cout << endl << player2.name << " lunges at " << name << ", dealing " << player2temp_attack << " damage." << endl;
                health -= player2temp_attack;
                picture_fight(player2temp_attack, -1, "fight", 0, 0);

                statupdate();
                print();
                cout << endl;
                player2.statupdate();
                player2.print();
                player2temp_proficiency += 1;
            }
            if(choice2 == 2)
            {
                cout << "What spell would you like to use?" << endl;
                for(i=0; i<5; i++)
                    if(spell[i] != "none") cout << setw(9) << player2.spell[i] << "   " << player2.damage[i] << endl;
                cin >> answer;
                if(answer == player2.spell[j]) player2turn += 1;
                else turn = 0;
                for(j=0; j<5; j++)
                    if(answer == player2.spell[j]) break;

                player2temp_attack = player2.damage[j] + (rand()%5) - equipped_defence;
                if(player2temp_attack <0) player2temp_attack = 1;

                cout << player2.name << " casts a " << player2.spell[j] << " spell at " << name << ", dealing " << player2temp_attack << " damage." << endl;
                player2.picture_fight(player2temp_attack, -1, "fight", 0, 0);
                health -= player2temp_attack;

                if(health < 0) health = 0;
                if(player2.health < 0) player2.health = 0;
                print();
                player2.print();
                statupdate();
                player2.statupdate();
                player2temp_magic_xp += 1;
                player2turn += 1;
            }
        }while(choice2 > 5);

        if(choice2 == 0)
        {
            cout << player2.name << " has run away from " << name << "!" << endl;
            break;
        }

        switch(choice)
        {
            case 2:
                    cout << name << ", it costs an extra 5 proficiency points to heal yourself while in battle. Do you wish to continue?" << endl;
                    cin >> answer;
                    if(answer == "yes" || answer == "Yes")
                    {
                        heal("self");
                        equipped_proficiency -= 5;
                        for(i=0; i<5; i++)
                            if(equipped_weapon == weapon[i].name) weapon[i].proficiency = equipped_proficiency;
                    }
                    break;
            case 3:
                    cout << name << "'s Inventory: " << endl;
                    for(i=0; i<9; i++)
                    {

                        if(item[i].name != "none") cout << item[i].name << "  " << item[i].healing << " healing power" << endl;

                    }
                    cout << "What would you like to use?" << endl;
                    cin >> answer;
                    if(answer == "food")
                    {
                        for(i=0; i<9; i++)
                        {
                            if(item[i].name == "food")
                            {
                                item_check = "true";
                                break;
                            }
                            else item_check = "false";
                        }
                        if(item_check == "true")
                        {
                            health += item[i].healing;
                            if(health >= max_health) health = max_health;
                            item[i].destroy();
                            break;
                        }
                        else if(item_check == "false") cout << "You don't have any food." << endl;
                    }
                    else if(answer == "roast")
                    {
                        for(i=0; i<9; i++)
                        {
                            if(item[i].name == "roast")
                            {
                                item_check = "true";
                                break;
                            }
                            else item_check = "false";
                        }
                        if(item_check == "true")
                        {
                            health += item[i].healing;
                            if(health >= max_health) health = max_health;
                            item[i].destroy();
                            break;
                        }
                        else if(item_check == "false") cout << "You don't have any roasts." << endl;
                    }
                    else if(answer == "chicken")
                    {
                        for(i=0; i<9; i++)
                        {
                            if(item[i].name == "chicken")
                            {
                                item_check = "true";
                                break;
                            }
                            else item_check = "false";
                        }
                        if(item_check == "true")
                        {
                            health += item[i].healing;
                            if(health >= max_health) health = max_health;
                            item[i].destroy();
                            break;
                        }
                        else if(item_check == "false") cout << "You don't have any chicken." << endl;
                    }
                    else cout << "Invalid choice" << endl;
                    turn += 1;
                    break;
            case 4:
                    cout << name << ", ";
                    equip();
                    break;
        }

        switch(choice2)
        {
            case 2:
                    cout << player2.name << ", it costs an extra 5 proficiency points to heal yourself while in battle. Do you wish to continue?" << endl;
                    cin >> answer;
                    if(answer == "yes" || answer == "Yes")
                    {
                        player2.heal("self");
                        player2.equipped_proficiency -= 5;
                        for(i=0; i<5; i++)
                            if(player2.equipped_weapon == player2.weapon[i].name) player2.weapon[i].proficiency = player2.equipped_proficiency;
                    }
                    break;
            case 3:
                    cout << player2.name << "'s Inventory: " << endl;
                    for(i=0; i<9; i++)
                    {

                        if(player2.item[i].name != "none") cout << player2.item[i].name << "  " << player2.item[i].healing << " healing power" << endl;

                    }
                    cout << "What would you like to use?" << endl;
                    cin >> answer;
                    if(answer == "food")
                    {
                        for(i=0; i<9; i++)
                        {
                            if(player2.item[i].name == "food")
                            {
                                item_check = "true";
                                break;
                            }
                            else item_check = "false";
                        }
                        if(item_check == "true")
                        {
                            player2.health += player2.item[i].healing;
                            if(player2.health >= player2.max_health) player2.health = player2.max_health;
                            player2.item[i].destroy();
                            break;
                        }
                        else if(item_check == "false") cout << "You don't have any food." << endl;
                    }
                    else if(answer == "roast")
                    {
                        for(i=0; i<9; i++)
                        {
                            if(player2.item[i].name == "roast")
                            {
                                item_check = "true";
                                break;
                            }
                            else item_check = "false";
                        }
                        if(item_check == "true")
                        {
                            player2.health += player2.item[i].healing;
                            if(player2.health >= player2.max_health) player2.health = player2.max_health;
                            player2.item[i].destroy();
                            break;
                        }
                        else if(item_check == "false") cout << "You don't have any roasts." << endl;
                    }
                    else if(answer == "chicken")
                    {
                        for(i=0; i<9; i++)
                        {
                            if(player2.item[i].name == "chicken")
                            {
                                item_check = "true";
                                break;
                            }
                            else item_check = "false";
                        }
                        if(item_check == "true")
                        {
                            player2.health += player2.item[i].healing;
                            if(player2.health >= player2.max_health) player2.health = player2.max_health;
                            player2.item[i].destroy();
                            break;
                        }
                        else if(item_check == "false") cout << "You don't have any chicken." << endl;
                    }
                    else cout << "Invalid choice" << endl;
                    turn += 1;
                    break;
            case 4:
                    cout << player2.name << ", ";
                    player2.equip();
                    break;
        }
    } while(choice != 0 && choice2 != 0 && health > 0 && player2.health > 0);
    if(health <= 0)
    {
        cout << player2.name << " has killed you!" << endl;
        picture_fight(temp_attack, player2temp_attack, "lose", 0, 0);
        player2.picture_fight(0, 0, "win", temp_gold, temp_experience);
        player2.experience += temp_experience;
        player2.equipped_proficiency += player2temp_proficiency;
        player2.gold += temp_gold;
        cout << player2.name << " has gained " << temp_experience << " experience and has scavenged " << temp_gold << " gold pieces from the corpse." << endl;
        gold -= temp_gold;
        experience -= temp_experience;
        statupdate();
        player2.statupdate();

        for(i=0; i<3; i++)
        if(player2.weapon[i].name == player2.equipped_weapon) player2.weapon[i].proficiency = player2.equipped_proficiency;
    }
    else if(player2.health <= 0)
    {
        player2.picture_fight(0, 0, "lose", 0, 0);
        picture_fight(temp_attack, player2temp_attack, "win", player2temp_gold, player2temp_experience);
        cout << "You have defeated " << player2.name << "! ";
        experience += player2temp_experience;
        equipped_proficiency += temp_proficiency;
        gold += player2temp_gold;
        cout << name << " has gained " << player2temp_experience << " experience and has scavenged " << player2temp_gold << " gold pieces from the corpse." << endl;
        player2.experience -= player2temp_experience;
        player2.gold -= player2temp_gold;
        statupdate();
        player2.statupdate();

        for(i=0; i<3; i++)
        if(weapon[i].name == equipped_weapon) weapon[i].proficiency = equipped_proficiency;
    }
    player2.save();
    save();
}

void Hero::move(string direction, string location)
{
    int random_orc, i, j, item_drop, choice, choice2;
    string monster, item_check;
    char decision;

    if(direction == "left")
    {
        x -= 1;
        if(location == "mine")
        {
            if(map[x][y] == '\\' || map[x][y] == '/' || map[x][y] == '|' || map[x][y] == '_' || map[x][y] == '^')
            {
                cout << "You cannot run through a wall." << endl;
                x += 1;
            }
            else map[x+1][y] = ' ';
        }
        else if(location == "city")
        {
            if(city[x][y] == '\\' || city[x][y] == '/' || city[x][y] == '|' || city[x][y] == '_' || city[x][y] == '~' || city[x][y] == '^')
            {
                cout << "You cannot run through a wall." << endl;
                x += 1;
            }
            else city[x+1][y] = ' ';
        }
    }
    if(direction == "right")
    {
        x += 1;
        if(location == "mine")
        {
            if(map[x][y] == '\\' || map[x][y] == '/' || map[x][y] == '|' || map[x][y] == '_')
            {
                cout << "You cannot run through a wall." << endl;
                x -= 1;
            }
            else map[x-1][y] = ' ';
        }
        else if(location == "city")
        {
            if(city[x][y] == '\\' || city[x][y] == '/' || city[x][y] == '|' || city[x][y] == '_' || city[x][y] == '~' || city[x][y] == '^')
            {
                cout << "You cannot run through a wall." << endl;
                x -= 1;
            }
            else city[x-1][y] = ' ';
        }
    }
    if(direction == "up")
    {
        y -= 1;
        if(location == "mine")
        {
            if(map[x][y] == '\\' || map[x][y] == '/' || map[x][y] == '|' || map[x][y] == '_')
            {
                cout << "You cannot run through a wall." << endl;
                y += 1;
            }
            else map[x][y+1] = ' ';
        }
        else if(location == "city")
        {
            if(city[x][y] == '\\' || city[x][y] == '/' || city[x][y] == '|' || city[x][y] == '_' || city[x][y] == '~' || city[x][y] == '^')
            {
                cout << "You cannot run through a wall." << endl;
                y += 1;
            }
            else city[x][y+1] = ' ';
        }
    }
    if(direction == "down")
    {
        y += 1;
        if(location == "mine")
        {
            if(map[x][y] == '\\' || map[x][y] == '/' || map[x][y] == '|' || map[x][y] == '_')
            {
                cout << "You cannot run through a wall." << endl;
                y -= 1;
            }
            else map[x][y-1] = ' ';
        }
        else if(location == "city")
        {
            if(city[x][y] == '\\' || city[x][y] == '/' || city[x][y] == '|' || city[x][y] == '_' || city[x][y] == '~' || city[x][y] == '^')
            {
                cout << "You cannot run through a wall." << endl;
                y -= 1;
            }
            else city[x][y-1] = ' ';
        }
    }

    if(location == "mine")
    {
        if(map[x][y] == 'o' || map[x][y] == 'O' || map[x][y] == 'b' || map[x][y] == 'B')
        {
            if(map[x][y] == 'o' || map[x][y] == 'O')
            {
                map[x][y] = 'O';
                random_orc = 1 + rand()%2;
                if(random_orc == 1) monster = "orc";
                if(random_orc == 2) monster = "gnome";
            }
            if(map[x][y] == 'b' || map[x][y] == 'B')
            {
                map[x][y] = 'B';
                monster = "goblin";
            }
            if(direction == "left")
                x += 1;
            if(direction == "right")
                x -= 1;
            if(direction == "down")
                y -= 1;
            if(direction == "up")
                y += 1;
            cout << "There is a " << monster << " blocking your way!" << endl;
            if(train(monster, "wild"))
            {
                if(direction == "left")
                {
                    x -= 1;
                    map[x+1][y] = ' ';
                }
                if(direction == "right")
                {
                    x += 1;
                    map[x-1][y] = ' ';
                }
                if(direction == "down")
                {
                    y += 1;
                    map[x][y-1] = ' ';
                }
                if(direction == "up")
                {
                    y -= 1;
                    map[x][y+1] = ' ';
                }
                map[x][y] = 'X';

                for(i=0; i<9; i++)
                    if(item[i].name != "none")
                    {
                        item_check = "true";
                        break;
                    }
                if(item_check == "true")
                {
                    item_drop = rand()%7;
                    if(item_drop == 0)
                    {
                        item[i].create("rusty_dagger", 0, 6);
                        cout << "You find a rusty dagger on the orc's corpse. Perhaps you can sell it at the shop." << endl;
                    }
                    if(item_drop == 1)
                    {
                        item[i].create("ruby", 0, 35);
                        cout << "A ruby clatters away from the corpse as it falls. It looks like it could be worth some gold." << endl;
                    }
                    if(item_drop == 2)
                    {
                        item[i].create("emerald", 0, 35);
                        cout << "An emerald falls away from the corpse as it collapses. Maybe you could add it to your weapon." << endl;
                    }
                    if(item_drop == 3)
                    {
                        item[i].create("sapphire", 0, 35);
                        cout << "A sapphire of a startling blue color catches your attention." << endl;
                    }
                    if(item_drop == 4)
                    {
                        item[i].create("diamond", 0, 45);
                        cout << "A diamond falls to the floor as you strike the last blow. It is definitely worth some gold." << endl;
                    }
                }
            }
        }
        else if(map[x][y] == 'a')
        {
            if(quest[1] == "none")
            {
                cout << "You have found an amulet. It looks important." << endl;
                quest[1] = "Find_owner_of_amulet.";
            }
            if(quest[1] == "Retrieve_the_amulet_in_the_mine_for_the_old_man")
            {
                cout << "You have found the old man's amulet. You should bring it back to him." << endl;
                quest[1] = "Give_the_amulet_back_to_the_old_man";
            }
        }
        map[x][y] = 'X';
    }




    if(location == "city")
    {
        if(x == 5 && y == 4)
        {
            //mayor
            if(level < 2)
                cout << "The mayor of Argon warns you of the danger. He will not give you the key to the mine until you have trained yourself to level 2." << endl;
            else if(level >= 2)
            {
                if(quest[0] == "Talk_to_the_mayor_and_get_the_key_to_the_mine")
                {
                    cout << "The mayor cautiously hands you the key to the mine, and you set out to enter the mine." << endl;
                    quest[0] = "Use_the_key_to_open_the_mine";
                }
                else cout << "The mayor is wringing his hands as he talks to you. 'I really need those monsters in the mine gone.'" << endl;
            }
            city[x][y] = ' ';
            y = 3;
            city[x][y] = 'X';
        }
        else if(x == 12 && y == 18)
        {
            heal("healer");
            city[x][y] = ' ';
            x = 13;
            city[x][y] = 'X';
        }
        else if(x == 11 && y == 25)
        {
            //train
            cout << "\nWe currently have the following monsters for you to train against: " << endl;
            cout << " (1) Orc \n (2) Gnome \n (3) Goblin"<< endl;
            do
            {
                cin >> decision;
                switch(decision)
                {
                    case '1':
                        monster = "orc";
                        break;
                    case '2':
                        monster = "gnome";
                        break;
                    case '3':
                        monster = "goblin";
                        break;
                    default:
                        cout << "Try again." << endl;
                        break;
                }
                cout << "You step into the arena opposite the " << monster << "." << endl;
                train(monster, "arena");
            }  while(decision > '3');

            city[x][y] = ' ';
            x = 12;
            city[x][y] = 'X';
        }
        else if(x == 13 && y == 6)
        {
            cout << "You walk into the tavern. It is noisy and packed full of people. A cloud of smoke seems to have permanantly made its home on the ceiling." << endl;
            tavern("Argon");
            city[x][y] = ' ';
            x = 12;
            city[x][y] = 'X';
        }
        else if(x == 18 && y == 22)
        {
            shop_weapon();
            city[x][y] = ' ';
            x = 19;
            city[x][y] = 'X';
        }
        else if(x == 21 && y == 22)
        {
            shop_armor();
            city[x][y] = ' ';
            x = 20;
            city[x][y] = 'X';
        }
        else if(x == 18 && y == 26)
        {
            shop_item();
            city[x][y] = ' ';
            x = 19;
            city[x][y] = 'X';
        }
        else if(x == 21 && y == 26)
        {
            shop_upgrade();
            city[x][y] = ' ';
            x = 20;
            city[x][y] = 'X';
        }

        if(city[x][y] == '&' || city[x][y] == '$')
        {
            cout << "You have found an abandoned treasure chest!" << endl;
            cout << "Inside you find 50 gold pieces, 2 rubies and a jeweled sword." << endl;
            for(j=0; j<3; j++)
                for(i=0; i<9; i++)
                {
                    if(item[i].name == "none")
                    {
                        item_check = "true";
                        item[i].name = "space";
                        break;
                    }
                    else item_check = "false";
                }
            if(item_check == "false")
            {
                cout << "You don't have enough room in your inventory to carry all these. Come back after you've cleared up some inventory." << endl;
                city[x][y] = '$';

                if(direction == "left")
                    x += 1;
                if(direction == "right")
                    x -= 1;
                if(direction == "down")
                    y -= 1;
                if(direction == "up")
                    y += 1;

                for(i=0; i<9; i++)
                    if(item[i].name == "space") item[i].name = "none";
            }
            if(item_check == "true")
            {
                for(i=0; i<9; i++)
                    if(item[i].name == "space")
                    {
                        item[i].create("ruby", 0, 35);
                        break;
                    }
                for(i=0; i<9; i++)
                    if(item[i].name == "space")
                    {
                        item[i].create("ruby", 0, 35);
                        break;
                    }
                for(i=0; i<9; i++)
                    if(item[i].name == "space")
                    {
                        item[i].create("jeweled_sword", 0, 40);
                        break;
                    }
            }
        }
    if(city[x][y] == '!')
    {
        cout << "You jump back as you hear a grinding sound, coming from the south." << endl;
        city[x][y] = ' ';
        if(direction == "left")
            x += 1;
        if(direction == "right")
            x -= 1;
        if(direction == "down")
            y -= 1;
        if(direction == "up")
            y += 1;
        city[2][20] = ' ';
        for(j=0; j<30; j++)
            for(i=0; i<25; i++)
                if(city[i][j] == '[') city[i][j] = '^';
    }
    city[x][y] = 'X';
    }
}

void Hero::tavern(string place)
{
    int choice, choice2, i;
    string item_check;

    if(place == "Argon")
    {
        do
        {
            cout << "\nWhat would you like to do?" << endl;
            cout << " (1) Buy a flagon of ale    5 gold \n (2) Buy a meal             10 gold \n (3) Ask the bartender about the mine \n (4) Talk to some of the patrons \n (0) Exit" << endl;
            cin >> choice2;
            switch(choice2)
            {
                case 0:
                        cout << "The bartender nods to you as you head out the door." << endl;
                        break;
                case 1:
                        //ale
                        if(gold >= 5)
                        {
                            cout << "The bartender hands you a glass and nods at you appreciatively as you hand over 5 gold coins. The ale relieves some stress, but leaves you feeling a bit lightheaded." << endl;
                            gold -= 5;
                        }
                        else cout << "The bartender gives you a look. 'Do you have enough gold to pay me?'" << endl;
                        break;
                case 2:
                        //meal
                        if(gold >= 10)
                        {
                            cout << "The bartender hands you a plate full of steaming hot food. You eagerly scarf it down and feel it warming you up." << endl;
                            gold -= 10;
                            health += 7;
                            if(health > max_health) health = max_health;
                        }
                        else cout << "The bartender gives you a look. 'Do you have enough gold to pay me?'" << endl;
                        break;
                case 3:
                        //bartender questions
                        cout << "You ask the bartender about the mine. He gives you a strange look, and tells you you're better off not going in there.";
                        cout << " You are persistant however, and finally he relents. He tells you there have been monsters coming out of the depths of ";
                        cout << "the mine for a while now. But there have been a few sightings of some strange beasts..." << endl;
                        cout << "\nBut that's just rumors of course." << endl;
                        break;
                case 4:
                        //patrons
                        if(quest[1] == "none" && quest_check != "old_man")
                        {
                            cout << "You notice there is a man leaning against the wall staring at you. You go over to confront him." << endl;
                            cout << "'Hello there stranger. Name's John. I'm a miner for the town of Argon. At least I used to be.'" << endl;
                            cout << " (1) Ask what happened." << endl;
                            cin >> choice;
                            cout << "He scoffs. 'Monsters! They took over our mine! They came from the depths and started overrunning us. At first it was manageable, but they just wouldn't stop coming. We had to seal off the mine. The mayor has the key to it, but he won't let anyone go back." << endl;
                            cout << "'But enough about me. What is a person like you doing in a little town like this?'" << endl;
                            cout << " (1) Tell him your story \n (2) Tell him to butt out" << endl;
                            cin >> choice;
                            if(choice == 2)
                                cout << "'Fine your business is your own. And I wish you the best of luck with whatever you're doing.'" << endl;
                            if(choice == 1)
                            {
                                cout << "'Oh! You're a noble one!' He laughs at you. Well I'll tell you what. If you're really going to go into the mine, see if you can't fetch my amulet for me. It dropped as I was fighting an orc on my way out of the mine. I'd really like it back." << endl;
                                cout << " (1) Accept his quest \n (2) You're too busy right now" << endl;
                                cin >> choice;
                                if(choice == 2)
                                    cout << "The old man doesn't seem too troubled by it. 'Oh well, maybe some other time.' He tells you as he turns back to his drink." << endl;
                                if(choice == 1)
                                {
                                    cout << "The old man thanks you and turns back to his drink." << endl;
                                    quest[1] = "Retrieve_the_amulet_in_the_mine_for_the_old_man";
                                }
                            }
                        }
                        else if(quest[1] == "Retrieve_the_amulet_in_the_mine_for_the_old_man") cout << "Have you found my amulet yet?" << endl;
                        if(quest[1] == "Find_owner_of_amulet" || quest[1] == "Give_the_amulet_back_to_the_old_man")
                        {
                            cout << "Thanks much! I thought I had lost this thing for good. Here something as payment." << endl;
                            cout << "\nYou receive 200 experience points. \nYou receive 50 gold pieces. \nYou receive the old man's battle axe." << endl;
                            experience += 200;
                            gold += 50;
                            quest[1] = "none";
                            quest_check = "old_man";
                            for(i=0; i<3; i++)
                                if(weapon[i].name == "none")
                                {
                                    item_check = "true";
                                    break;
                                }
                                else item_check = "false";
                            if(item_check == "true")
                                weapon[i].create("battle_axe", 5, 10);
                            else if(item_check == "false") cout << "You don't have enough space to carry the battle axe." << endl;
                        }
                        if(quest_check == "old_man")
                            cout << "The patrons look at you uneasily. They don't trust strangers." << endl;
                        break;
                default:
                        cout << "Invalid choice." << endl;
                        break;
            }
        }while(choice2 != 0);
    }

}

void Hero::set_map(string place)
{
    int i, j;

    if(place == "mine")
    {
        for(i=0; i<21; i++)
        {
            for(j=0; j<37; j++)
                map[i][j] = ' ';
        }
        for(j=0; j<6; j++)
        {
            map[11][j] = '|';
            map[13][j] = '|';
        }
        for(i=7; i<11; i++)
            map[i][5] = '_';
        for(i=14; i<18; i++)
            map[i][5] = '_';
        for(j=6; j<9; j++)
        {
            map[7][j] = '|';
            map[17][j] = '|';
        }
        map[7][9] = '|';
        map[8][10] = '\\';
        map[9][11] = '\\';
        map[10][12] = '|';
        map[18][9] = '|';
        map[19][10] = '|';
        map[20][11] = '|';
        map[20][12] = '|';
        for(i=10; i<21; i++)
            map[i][13] = '^';
        map[10][7] = 'o';
        map[10][10] = 'o';
        map[16][6] = 'o';
        map[14][9] = 'o';
        map[17][10] = '/';
        map[16][11] = '/';
        map[16][12] = 'b';
        map[18][10] = 's';
        map[18][11] = 'b';
        map[18][12] = 'b';
        map[19][12] = 't';
    }
    else if(place == "Argon")
    {
        for(i=0; i<25; i++)
            for(j=0; j<30; j++)
                city[i][j] = ' ';

        city[2][24] = '&';
        city[20][11] = '!';

        //outside
        for(j=10; j<18; j++)
            city[0][j] = '[';
        city[1][18] = '[';
        city[1][19] = '[';
        city[1][20] = '[';
        for(j=0; j<3; j++)
        {
            city[9][j] = '|';
            city[11][j] = '|';
        }
        for(i=1; i<9; i++)
            city[i][2] = '_';
        for(i=12; i<22; i++)
            city[i][2] = '_';
        for(j=3; j<10; j++)
            city[0][j] = '|';
        for(i=1; i<6; i++)
            city[i][9] = '_';
        for(j=10; j<21; j++)
            city[6][j] = '|';
        for(i=2; i<6; i++)
            city[i][20] = '_';
        for(j=21; j<29; j++)
            city[1][j] = '|';
        for(i=2; i<24; i++)
            city[i][29] = '^';
        for(j=20; j<29; j++)
            city[24][j] = '|';
        city[20][19] = '_';
        city[21][19] = '_';
        city[22][19] = '_';
        city[23][19] = '_';
        city[19][19] = '\\';
        city[18][18] = '\\';
        city[17][17] = '|';
        city[17][16] = '|';
        city[18][15] = '/';
        city[19][14] = '/';
        city[20][13] = '/';
        city[21][12] = '/';
        for(j=3; j<12; j++)
            city[22][j] = '|';

        //mayor
        city[3][6] = 'm';
        city[4][6] = 'a';
        city[5][6] = 'y';
        city[6][6] = 'o';
        city[7][6] = 'r';
        for(j=4; j<8; j++)
        {
            city[2][j] = '~';
            city[8][j] = '~';
        }
        for(i=2; i<9; i++)
        {
            city[i][4] = '~';
            city[i][7] = '~';
        }
        city[5][4] = ' ';

        //tavern
        city[17][6] = 't';
        city[17][7] = 'a';
        city[17][8] = 'v';
        city[17][9] = 'e';
        city[17][10] = 'r';
        city[17][11] = 'n';
        for(i=13; i<21; i++)
            city[i][4] = '~';
        for(j=4; j<11; j++)
            city[20][j] = '~';
        city[13][5] = '~';
        city[13][7] = '~';
        city[13][8] = '~';
        city[14][9] = '~';
        city[15][10] = '~';
        city[15][11] = '~';
        city[16][12] = '~';
        city[17][13] = '~';
        city[18][12] = '~';
        city[19][11] = '~';

        //healer
        city[8][13] = 'h';
        city[8][14] = 'e';
        city[8][15] = 'a';
        city[8][16] = 'l';
        city[8][17] = 'e';
        city[8][18] = 'r';
        for(j=11; j<21; j++)
            city[7][j] = '~';
        for(i=7; i<13; i++)
            city[i][20] = '~';
        for(j=15; j<21; j++)
            city[12][j] = '~';
        city[11][14] = '~';
        city[10][13] = '~';
        city[9][12] = '~';
        city[8][11] = '~';
        city[12][18] = ' ';

        //arena
        city[5][24] = 'a';
        city[6][24] = 'r';
        city[7][24] = 'e';
        city[8][24] = 'n';
        city[9][24] = 'a';
        for(i=3; i<12; i++)
        {
            city[i][22] = '~';
            city[i][27] = '~';
        }
        for(j=22; j<27; j++)
        {
            city[3][j] = '~';
            city[11][j] = '~';
        }
        city[11][25] = ' ';

        //shop
        for(j=21; j<24; j++)
        {
            city[17][j] = '~';
            city[22][j] = '~';
            city[17][j+4] = '~';
            city[22][j+4] = '~';
        }
        for(j=10; j<14; j++)
        {
            city[18][(j*2)+1] = '~';
            city[21][(j*2)+1] = '~';
        }
    }

}


#include <cstdlib>
#include <iostream>
#include "hero.h"

using namespace std;

int main()
{
    cout << "****************************************" << endl;
    cout << "*  .  *         .            .         *" << endl;
    cout << "*       .              *               *" << endl;
    cout << "*             An RPG Game       *      *" << endl;
    cout << "*   .        by Jordan Reed            *" << endl;
    cout << "*        *                        .    *" << endl;
    cout << "*        .         .     *             *" << endl;
    cout << "*   *                          *       *" << endl;
    cout << "*    .      *          .         .     *" << endl;
    cout << "****************************************" << endl;

    Hero hero;
    int choice, i, answer;

    if(hero.save_point == "Argon" || hero.save_point == "Argon_mine")
        do
        {
            hero.statupdate();
            cout << "\nWhat would you like to do?" << endl;
            cout << " (1) Open inventory \n";
            cout << " (2) Show stats \n";
            cout << " (3) Show current quests \n";
            cout << " (4) Equip items \n\n";
            cout << " (5) Enter the town of Argon \n";
            cout << " (6) Enter the mine \n\n";
            cout << " (7) Fight another player \n";
            cout << " (0) Save and Exit" << endl;
            cin >> choice;
            
            switch(choice)
            {
                case 1:
                        hero.print_inventory();
                        break;
                case 2:
                        hero.statprint();
                        break;
                case 3:
                        hero.print_quests();
                        break;
                case 4:
                        hero.equip();
                        break;
                case 5:
                        if(hero.health <= 0)
                        {
                            cout << "You must be ressurected first." << endl;
                            break;
                        }
                        if(hero.quest[0] == "Save_the_citizens_of_Argon_from_the_monsters_in_the_mine") hero.quest[0] = "Talk_to_the_mayor_and_get_the_key_to_the_mine";
                        hero.location("Argon");
                        break;
                case 6:
                        if(hero.health <= 0)
                        {
                            cout << "You must be ressurected first." << endl;
                            break;
                        }
                        if(hero.quest[0] == "Save_the_citizens_of_Argon_from_the_monsters_in_the_mine" || hero.quest[0] == "Talk_to_the_mayor_and_get_the_key_to_the_mine")
                        {
                            cout << "You have not received the key from the mayor of Argon. Go back to the town and get the key." << endl;
                            break;
                        }
                        else
                        {
                            hero.mine();
                            hero.time += 1;
                        }
                        break;
                case 7:
                        hero.fight_player();
                        break;
                default:
                        break;
            }
            if(hero.health <= 0)
            {
                do
                {
                    cout << "You have died and your health is low. It will cost you 10 extra proficiency points (not levels) to ressurect yourself. It will only come from the weapon you have equipped. \nWould you like to continue? \n (1) Yes \n(2) No" << endl;
                    cin >> answer;
                    switch(answer)
                    {
                        case 0:
                                break;
                        case 1:
                                hero.equipped_proficiency -= 10;
                                hero.heal("self");
                                for(i=0; i<5; i++)
                                if(hero.equipped_weapon == hero.weapon[i].name) hero.weapon[i].proficiency = hero.equipped_proficiency;
                                break;
                        case 2:
                                choice = 8;
                                cout << "You may change what weapon you have equipped, but you will not be able to go into town or the mine until you have been ressurected." << endl;
                                break;
                        default:
                                cout << "Wrong answer. Try again." << endl;
                                break;
                    }
                }while(answer != 0);
            }
        }while(choice != 0);
    hero.save();
}

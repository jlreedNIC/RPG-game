#include "npc.h"

Npc::Npc()
{
    health = maxHealth = 10;
    name = "Bob";
    race = "human";
    charClass = "npc";
}

Npc::~Npc()
{
    // destructor
}


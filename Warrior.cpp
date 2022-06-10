#include "Warrior.hpp"

void Warrior::print() const
{
    printBrief();
    printItems();
}

void Warrior::printBrief() const
{
    Constants::STDOUT(getName())("\nWarrior\tlevel ")(getLevel())('\n');
    Troop::print((equip[0] ? equip[0]->getBonus() : 0));
    if (equip[2])
        Constants::STDOUT("\tSPELL DAMAGE: ")(attack * (1 + equip[2]->getBonus()))('\n');
}

bool Warrior::payCost(float points)
{
    return Troop::payMana(points);
}

void Warrior::levelUp()
{
    Troop::levelUp();
    printBrief();
}

void Warrior::save(const String &game) const
{
    String file = "games\\";
    file += game;
    file += ".dndplayer";
    std::ofstream ofs(file);

    // todo
    // Player::save(ofs);
    // Troop::save(ofs);

    ofs.close();
}
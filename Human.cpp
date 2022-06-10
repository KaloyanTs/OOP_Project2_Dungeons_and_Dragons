#include "Human.hpp"

void Human::print() const
{
    printBrief();
    printItems();
}

void Human::printBrief() const
{
    Constants::STDOUT(getName())("\nHuman\tlevel ")(getLevel())('\n');
    Troop::print((equip[0] ? equip[0]->getBonus() : 0));
    if (equip[2])
        Constants::STDOUT("\tSPELL DAMAGE: ")(attack * (1 + equip[2]->getBonus()))('\n');
}

bool Human::payCost(float points)
{
    return Troop::payMana(points);
}

void Human::levelUp()
{
    Troop::levelUp();
    printBrief();
}

void Human::save(const String &game) const
{
    String file = "games\\";
    file += game;
    file += ".dndplayer";
    std::ofstream ofs(file);

    std::cout << "to be saved...";
    getch();
    // fix work on this

    // todo
    // Player::save(ofs);
    // Troop::save(ofs);

    ofs.close();
}
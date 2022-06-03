#include "Human.hpp"

void Human::print() const
{
    printBrief();
    printItems();
}

void Human::printStats() const
{
    print();
}

void Human::printBrief() const
{
    // todo add equipments
    Constants::STDOUT(getName())("\nHuman\tlevel ")(getLevel())('\n');
    Troop::print((equip[0] ? equip[0]->getBonus() : 0));
    if (equip[2])
        Constants::STDOUT("\tSPELL DAMAGE: ")(attack * (1 + equip[2]->getBonus()))('\n');
}

bool Human::payCost(float points)
{
    return Troop::payMana(points);
}
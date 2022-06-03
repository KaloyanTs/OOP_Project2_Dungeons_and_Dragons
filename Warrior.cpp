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
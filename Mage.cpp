#include "Mage.hpp"

void Mage::print() const
{
    printBrief();
    printItems();
}

void Mage::printBrief() const
{
    Constants::STDOUT(getName())("\nMage\tlevel ")(getLevel())('\n');
    Troop::print((equip[0] ? equip[0]->getBonus() : 0));
    if (equip[2])
        Constants::STDOUT("\tSPELL DAMAGE: ")(attack * (1 + equip[2]->getBonus()))('\n');
}

bool Mage::payCost(float points)
{
    return Troop::payMana(points);
}
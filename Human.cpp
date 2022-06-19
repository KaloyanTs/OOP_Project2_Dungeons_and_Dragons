#include "Human.hpp"

void Human::print() const
{
    printBrief();
    printItems();
}

void Human::printBrief() const
{
    Constants::out << getName() << "\nHuman\tlevel " << getLevel() << "\t(" << xpNeeded << "xp needed)\n";
    Troop::print((equip[0] ? equip[0]->getBonus() : 0));
    if (equip[2])
        Constants::out << "\tSPELL DAMAGE(" << equip[2]->getCost() << " mana): "
                       << attack * (1 + equip[2]->getBonus()) << '\n';
}
#include "Mage.hpp"

void Mage::print() const
{
    printBrief();
    printItems();
}

void Mage::printBrief() const
{
    Constants::out << getName() << "\nMage\tlevel " << getLevel() << "\t(" << xpNeeded << "xp needed)\n";
    Troop::print((equip[0] ? equip[0]->getBonus() : 0));
    if (equip[2])
        Constants::out << "\tSPELL DAMAGE: " << attack * (1 + equip[2]->getBonus()) << '\n';
}

void Mage::save(const String &game) const
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
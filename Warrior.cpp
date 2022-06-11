#include "Warrior.hpp"

void Warrior::print() const
{
    printBrief();
    printItems();
}

void Warrior::printBrief() const
{
    Constants::STDOUT(getName())("\nWarrior\tlevel ")(getLevel());
    Constants::STDOUT("\t(")(xpNeeded)("xp needed)\n");
    Troop::print((equip[0] ? equip[0]->getBonus() : 0));
    if (equip[2])
        Constants::STDOUT("\tSPELL DAMAGE: ")(attack * (1 + equip[2]->getBonus()))('\n');
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
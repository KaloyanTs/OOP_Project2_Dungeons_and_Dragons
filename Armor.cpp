#include "Armor.hpp"

void Armor::print() const
{
    HeroEquipment::print();
    Constants::out << name << '\n';
    Equipment::print();
    Constants::out << '\n';
}

Armor::Armor(unsigned y, unsigned x, unsigned bot, unsigned top, bool onBoard)
    : HeroEquipment(&GameAssets::armor_icon, y, x, std::min(top, 70u), bot, onBoard) { ArmorNameGenerator::getInstance().generateWord(name); }
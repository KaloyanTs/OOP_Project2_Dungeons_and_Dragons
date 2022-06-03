#include "Armor.hpp"

void Armor::print() const
{
    HeroEquipment::print();
    Constants::STDOUT(name)('\n');
    Equipment::print();
    Constants::STDOUT('\n');
}

Armor::Armor(unsigned y, unsigned x, unsigned bot, unsigned top, bool onBoard)
    : HeroEquipment(&GameAssets::armor_icon, y, x, top, bot, onBoard) { Constants::armor_name_generator.generateWord(name); }
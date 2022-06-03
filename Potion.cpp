#include "Potion.hpp"

Potion::Potion(unsigned y, unsigned x, unsigned bot, unsigned top, bool onBoard)
    : HeroEquipment(&GameAssets::potion_icon, y, x, top, bot, onBoard) { Constants::potion_name_generator.generateWord(name); }

void Potion::print() const
{
    HeroEquipment::print();
    Constants::STDOUT(name)('\n');
    Equipment::print();
    Constants::STDOUT('\n');
}
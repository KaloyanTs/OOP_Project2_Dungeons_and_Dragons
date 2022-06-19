#include "Potion.hpp"

Potion::Potion(unsigned y, unsigned x, unsigned bot, unsigned top, bool onBoard)
    : HeroEquipment(&GameAssets::potion_icon, y, x, top, bot, onBoard) { PotionNameGenerator::getIntance().generateWord(name); }

void Potion::print() const
{
    HeroEquipment::print();
    Constants::out << name << '\n';
    Equipment::print();
    Constants::out << '\n';
}
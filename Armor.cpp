#include "Armor.hpp"

void Armor::print() const
{
    HeroEquipment::print();
    Constants::STDOUT(name)('\n');
}

Armor::Armor(unsigned y, unsigned x, bool onBoard)
    : HeroEquipment(&GameAssets::armor_icon, y, x, onBoard) { Constants::armor_name_generator.generateWord(name); }

HeroEquipment *Armor::clone() const { return new Armor(*this); }
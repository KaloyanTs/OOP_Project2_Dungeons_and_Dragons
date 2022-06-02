#include "Spell.hpp"

Spell::Spell(unsigned y, unsigned x, unsigned bot, unsigned top, bool onBoard)
    : HeroEquipment(&GameAssets::spell_icon, y, x,bot,top, onBoard) { Constants::spell_name_generator.generateWord(name); }

void Spell::print() const
{
    HeroEquipment::print();
    Constants::STDOUT(name)('\n');
    Equipment::print();
    Constants::STDOUT('\n');
}

HeroEquipment *Spell::clone() const { return new Spell(*this); }
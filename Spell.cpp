#include "Spell.hpp"

Spell::Spell(unsigned y, unsigned x, bool onBoard)
    : HeroEquipment(&GameAssets::spell_icon, y, x, onBoard) { Constants::spell_name_generator.generateWord(name); }

void Spell::print(const Printer &p) const
{
    HeroEquipment::print(p);
    p(name)('\n');
}

HeroEquipment *Spell::clone() const { return new Spell(*this); }
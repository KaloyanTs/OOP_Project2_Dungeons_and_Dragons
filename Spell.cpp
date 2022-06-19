#include "Spell.hpp"

Spell::Spell(unsigned y, unsigned x, unsigned bot, unsigned top, bool onBoard, unsigned c)
    : HeroEquipment(&GameAssets::spell_icon, y, x, top, bot, onBoard), cost(c)
{
    SpellNameGenerator::getInstance().generateWord(name);
}

void Spell::print() const
{
    HeroEquipment::print();
    Constants::out << name << '\n';
    Equipment::print();
    Constants::out << "\tCost: " << cost << '\n';
}
#include "Weapon.hpp"

Weapon::Weapon(unsigned y, unsigned x, bool onBoard)
    : HeroEquipment(&GameAssets::attack_icon, y, x, onBoard) { Constants::weapon_name_generator.generateWord(name); }

void Weapon::print(const Printer &p) const
{
    HeroEquipment::print(p);
    p(name)('\n');
}

HeroEquipment *Weapon::clone() const { return new Weapon(*this); }
#ifndef __TROOP_HPP
#define __TROOP_HPP
#include "GameAssets.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"
#include "Spell.hpp"

class Troop
{

protected:
    const float maxHealth;
    float attack;
    float mana, health;

public:
    Troop(float _attack, float _mana, float _health)
        : attack(_attack),
          mana(_mana), health(_health), maxHealth(_health) {}
    virtual ~Troop() {}

    virtual Troop *clone() const = 0;
    virtual void print(const Printer &p) const;
};

#endif
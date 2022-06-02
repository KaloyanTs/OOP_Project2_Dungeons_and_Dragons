#ifndef __TROOP_HPP
#define __TROOP_HPP
#include "Constants.hpp"
#include "Printer.hpp"
#include "GameAssets.hpp"
#include "HeroEquipment.hpp"

class Troop
{

protected:
    unsigned level;
    const float maxHealth;
    float attack;
    float mana, health;

    float determineStat(unsigned lvl, float init, float perLevel) const;
    bool alive() const { return health > 0; }

public:
    Troop(float _attack, float _mana, float _health, unsigned lvl = 1)
        : attack(_attack),
          mana(_mana),
          health(_health),
          maxHealth(_health),
          level(lvl)
    {
    }
    virtual ~Troop() {}

    virtual Troop *clone() const = 0;
    virtual void print(float attackBonus = 0) const;
    unsigned getLevel() const { return level; }

    virtual void takeDamage(float dmg);
};

#endif
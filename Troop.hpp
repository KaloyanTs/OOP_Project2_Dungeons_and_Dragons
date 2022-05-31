#ifndef __TROOP_HPP
#define __TROOP_HPP
#include "Printer.hpp"
#include "GameAssets.hpp"

class Troop
{

protected:
    const float maxHealth;
    float attack;
    float mana, health;

    float determineStat(unsigned lvl, float init, float perLevel) const;

public:
    Troop(float _attack, float _mana, float _health)
        : attack(_attack),
          mana(_mana),
          health(_health),
          maxHealth(_health)
    {
    }
    virtual ~Troop() {}

    virtual Troop *clone() const = 0;
    virtual void print(const Printer &p) const;
};

#endif
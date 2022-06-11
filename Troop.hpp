#ifndef __TROOP_HPP
#define __TROOP_HPP
#include "Constants.hpp"
#include "Printer.hpp"
#include "GameAssets.hpp"
#include "HeroEquipment.hpp"

class Troop
{
    void levelUp();

protected:
    unsigned level;
    float maxHealth;
    float maxMana;
    float attack;
    float mana, health;
    unsigned xpNeeded;

    float determineStat(unsigned lvl, float init, float perLevel) const;
    bool alive() const { return Constants::greater(health, 0); }

    void save(std::ofstream &ofs) const;

public:
    Troop(float _attack, float _mana, float _health, unsigned lvl = 1)
        : attack(_attack),
          mana(_mana),
          health(_health),
          maxHealth(_health),
          maxMana(_mana),
          level(lvl),
          xpNeeded(lvl * XP_NEED_ACUMULATION)
    {
    }
    virtual ~Troop() {}

    virtual Troop *clone() const = 0;
    virtual void print(float attackBonus = 0) const;
    unsigned getLevel() const { return level; }

    virtual void takeDamage(float dmg);

    bool payMana(float points);

    void regen(float percentage = 0);

    void gainXP(unsigned gain);
};

#endif
#ifndef __TROOP_HPP
#define __TROOP_HPP
#include "Constants.hpp"
#include "GameAssets.hpp"
#include "HeroEquipment.hpp"

/// class representing something living on the map, having level, health, attack and mana
class Troop
{
    void levelUp();

protected:
    unsigned level;
    float maxHealth;
    float maxMana;
    float attack;
    float mana, health;
    /// XP needed to reach next level
    unsigned xpNeeded;

    /// determine value of a stat of some troop of particular level with some initial value and multiplier per level
    float determineStat(unsigned lvl, float init, float perLevel) const;
    /// check if this troop is alive (has positive health)
    bool alive() const { return Constants::greater(health, 0); }
    /// write info about this troop to a text file
    void save(std::ofstream &ofs) const;

public:
    /// construct a troop with attack, mana, health and level
    Troop(float _attack, float _mana, float _health, unsigned lvl = 1)
        : attack(_attack),
          mana(_mana),
          health(_health),
          maxHealth(_health),
          maxMana(_mana),
          level(lvl),
          xpNeeded(lvl * Constants::XP_NEED_ACUMULATION) {}
    /// construct troop by reading its data from text file
    Troop(std::ifstream &ifs);
    /// virtual destructor
    virtual ~Troop() {}

    virtual Troop *clone() const = 0;
    /// virtual function printing the stats of this troop
    virtual void print(float attackBonus = 0) const;
    unsigned getLevel() const { return level; }
    /// lower the health of this troop by some damage (health cannot be below 0)
    virtual void takeDamage(float dmg);
    /// pay amount of mana (to cast a spell for example)
    bool payMana(float points);
    /// regenerate health by some percentage (when percentage is 0 the troop is regenerated to half health)
    void regen(float percentage = 0);
    /// gain amount of XP (if enough it levels up)
    void gainXP(unsigned gain);
};

#endif
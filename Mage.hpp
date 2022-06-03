#ifndef __MAGE_HPP
#define __MAGE_HPP
#include "Player.hpp"
#include "Troop.hpp"

class Mage : public Player, public Troop
{
public:
    Mage(unsigned posY, unsigned posX, const String &name)
        : Player(posY, posX, name),
          Troop(Constants::MAGE_INIT_ATTACK,
                Constants::MAGE_INIT_MANA,
                Constants::MAGE_INIT_HEALTH) {}

    Mage *clone() const { return new Mage(*this); }
    void print() const;
    void printStats() const { print(); }
    bool alive() const { return Troop::alive(); }

    void printBrief() const;
    virtual float getAttack() const { return attack; }
    virtual float getHealth() const { return health; }
    virtual float getMana() const { return mana; }

    void takeDamage(float dmg) { Troop::takeDamage(dmg * (1 - (equip[1] ? equip[1]->getBonus() : 0))); }

    bool payCost(float points);
    void regenerate() { Troop::regen(); }
};

#endif
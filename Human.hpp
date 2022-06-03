#ifndef __HUMAN_HPP
#define __HUMAN_HPP
#include "Player.hpp"
#include "Troop.hpp"

class Human : public Player, public Troop
{
public:
    Human(unsigned posY, unsigned posX, const String &name = "unknown")
        : Player(posY, posX, name),
          Troop(Constants::HUMAN_INIT_ATTACK,
                Constants::HUMAN_INIT_MANA,
                Constants::HUMAN_INIT_HEALTH) {}

    Human *clone() const { return new Human(*this); }
    void print() const;
    void printStats() const;
    bool alive() const { return Troop::alive(); }

    void printBrief() const;
    virtual float getAttack() const { return attack; }
    virtual float getHealth() const { return health; }
    virtual float getMana() const { return mana; }

    void takeDamage(float dmg) { Troop::takeDamage(dmg * (1 - (equip[1] ? equip[1]->getBonus() : 0))); }

    bool payCost(float points);
};

#endif
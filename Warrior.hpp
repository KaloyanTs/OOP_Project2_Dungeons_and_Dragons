#ifndef __WARRIOR_HPP
#define __WARRIOR_HPP
#include "Player.hpp"
#include "Troop.hpp"

class Warrior : public Player, public Troop
{
public:
    Warrior(unsigned posY, unsigned posX, const String &name)
        : Player(posY, posX, name),
          Troop(Constants::WARRIOR_INIT_ATTACK,
                Constants::WARRIOR_INIT_MANA,
                Constants::WARRIOR_INIT_HEALTH) {}

    Warrior *clone() const { return new Warrior(*this); }
    void print() const;
    void printStats() const;
};

#endif
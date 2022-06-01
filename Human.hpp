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
};

#endif
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
    void print(const Printer &p) const;
    void printStats(const Printer &p) const;
};

#endif
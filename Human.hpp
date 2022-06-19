#ifndef __HUMAN_HPP
#define __HUMAN_HPP
#include "Player.hpp"
#include "Troop.hpp"

/// class representing specific type of player
class Human : public Player, public Troop
{

    HERO_TYPE getID() const { return HERO_TYPE::HUMAN; }
    void saveStats(std::ofstream &ofs) const { Troop::save(ofs); }

public:
    /// constructor of a human by position on the board and name
    Human(unsigned posY, unsigned posX, const String &name = "unknown")
        : Player(posY, posX, name),
          Troop(Constants::HUMAN_INIT_ATTACK,
                Constants::HUMAN_INIT_MANA,
                Constants::HUMAN_INIT_HEALTH) {}
    /// construct a human by reading its info from text file
    Human(std::ifstream &ifs)
        : Player(ifs),
          Troop(ifs) {}
    /// clone function
    Human *clone() const { return new Human(*this); }
    /// print human's name, level, stats
    void print() const;
    /// print human's name, level, stats, equipment and inventar
    void printStats() const { print(); }
    /// check if the human is alive (see Troop::alive())
    bool alive() const { return Troop::alive(); }
    /// print stats of this human
    void printBrief() const;
    virtual float getAttack() const { return attack; }
    virtual float getHealth() const { return health; }
    virtual float getMana() const { return mana; }
    /// take damage from an enemy (uses its armor if has)
    void takeDamage(float dmg) { Troop::takeDamage(dmg * (1 - (equip[1] ? equip[1]->getBonus() : 0))); }
    /// try to pay cost of a spell to cast it
    bool payCost(float points) { return Troop::payMana(points); }
    void regenerate(float percentage) { Troop::regen(percentage); }
    /// gain amount of XP (levels up if enough XP)
    void gainXP(unsigned gain) { Troop::gainXP(gain); }
};

#endif
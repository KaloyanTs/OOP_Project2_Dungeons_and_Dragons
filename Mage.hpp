#ifndef __MAGE_HPP
#define __MAGE_HPP
#include "Player.hpp"
#include "Troop.hpp"

/// class representing specific type of player
class Mage : public Player, public Troop
{
    HERO_TYPE getID() const { return HERO_TYPE::MAGE; }
    void saveStats(std::ofstream &ofs) const { Troop::save(ofs); }

public:
    /// constructor of a mage by position on the board and name
    Mage(unsigned posY, unsigned posX, const String &name)
        : Player(posY, posX, name),
          Troop(Constants::MAGE_INIT_ATTACK,
                Constants::MAGE_INIT_MANA,
                Constants::MAGE_INIT_HEALTH) {}
    /// construct a mage by reading its info from text file
    Mage(std::ifstream &ifs)
        : Player(ifs),
          Troop(ifs) {}
    /// clone function
    Mage *clone() const { return new Mage(*this); }
    /// print mage's name, level, stats
    void print() const;
    /// print mage's name, level, stats, equipment and inventar
    void printStats() const { print(); }
    /// check if the mage is alive (see Troop::alive())
    bool alive() const { return Troop::alive(); }
    /// print stats of this mage
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
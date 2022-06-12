#ifndef __WARRIOR_HPP
#define __WARRIOR_HPP
#include "Player.hpp"
#include "Troop.hpp"

class Warrior : public Player, public Troop
{
    HERO_TYPE getID() const { return HERO_TYPE::WARRIOR; }
    void saveStats(std::ofstream &ofs) const { Troop::save(ofs); }

public:
    /// constructor of a warrior by position on the board and name
    Warrior(unsigned posY, unsigned posX, const String &name)
        : Player(posY, posX, name),
          Troop(Constants::WARRIOR_INIT_ATTACK,
                Constants::WARRIOR_INIT_MANA,
                Constants::WARRIOR_INIT_HEALTH) {}
    /// constructor of a warrior by position on the board and name
    Warrior(std::ifstream &ifs)
        : Player(ifs),
          Troop(ifs) {}
    /// clone function
    Warrior *clone() const { return new Warrior(*this); }
    /// print warrior's name, level, stats
    void print() const;
    /// print warrior's name, level, stats, equipment and inventar
    void printStats() const { print(); }
    /// check if the warrior is alive (see Troop::alive())
    bool alive() const { return Troop::alive(); }
    /// print stats of this warrior
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
    /// write the warrior's info into a text file
    void save(const String &game) const;
};

#endif
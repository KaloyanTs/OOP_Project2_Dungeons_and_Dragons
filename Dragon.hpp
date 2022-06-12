#ifndef __DRAGON_HPP
#define __DRAGON_HPP
#include "Constants.hpp"
#include "Troop.hpp"
#include "EventGenerator.hpp"

class Player;

/// class representing a dragon enemy of the player on the map
class Dragon : public Troop, public EventGenerator
{
    static String errorMsg;
    static const char stamp = 'M';
    const Image *pic;
    unsigned armor;
    String quote;

public:
    /// constructor of a dragon based on position on the map and level
    Dragon(unsigned y, unsigned x, unsigned lvl = 1)
        : Troop((unsigned)determineStat(lvl, 25, 1.2),
                (unsigned)determineStat(lvl, 25, 1.2),
                (unsigned)determineStat(lvl, 50, 1.2), lvl),
          EventGenerator(y, x, errorMsg),
          pic(&GameAssets::dragon),
          armor(Constants::DRAGON_ARMOR_INIT + (lvl - 1) * Constants::DRAGON_ARMOR_PER_LEVEL)
    {
        DragonQuoteGenerator::getInstance().generateWord(quote);
    }
    /// virtual clone function
    virtual Dragon *clone() const { return new Dragon(*this); }
    /// get the character representing a dragon on the map
    char getChar() const { return stamp; }
    /// initiate a battle between a player and this dragon; the result is either player escaped or battle took place and one of two is dead
    Constants::ACTION_STATE action(Player *, bool &);
    /// print dragon's image, quote and stats
    void print() const;
    /// take damage lowering this dragon' health; if below or equal to 0 the dragon is dead
    void takeDamage(float dmg) { Troop::takeDamage(dmg - armor * dmg / 100); }
    /// write this dragon's info into text file
    void write(std::ofstream &ofs) const;
};

#endif
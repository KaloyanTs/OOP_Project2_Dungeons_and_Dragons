#ifndef __PLAYER_HPP
#define __PLAYER_HPP
#include <conio.h>
#include <iostream>
#include "Inventar.hpp"
#include "Dragon.hpp"

/// enum storing keyboard keys used for playing
enum class KEYS
{
    NONE = 0,
    UP = 'w',
    DOWN = 's',
    LEFT = 'a',
    RIGHT = 'd',
    EXIT = '`'
};

bool operator==(char c, const KEYS &k);

/// class representing player moving on the board and interacting with event generators on it
class Player
{
public:
    /// ID's of different hero types
    enum class HERO_TYPE
    {
        HUMAN = 0,
        MAGE = 1,
        WARRIOR = 2,
        ERROR = 3
    };

private:
    static const char PLAYER_CHAR = (char)177;
    unsigned y, x;
    Inventar *inv;
    String name;

    HeroEquipment *&getMatching(const HeroEquipment *ptr);
    void printInventar() const;
    void inventar();
    virtual bool payCost(float points) = 0;
    virtual void saveStats(std::ofstream &ofs) const = 0;
    virtual HERO_TYPE getID() const = 0;

protected:
    /// equipment worn by the player
    HeroEquipment *equip[Constants::EQUIPMENT_COUNT];
    /// readind player from text file
    Player(std::ifstream &ifs);

public:
    /// construct player by its position on the board and name
    Player(unsigned posY, unsigned posX, const String &n);
    virtual ~Player();

    /// move the player on the map with keyboard keys if new position is allowed
    template <typename ALLOWED>
    bool move(bool &run, bool &pause, ALLOWED f);

    unsigned getY() const { return y; }
    unsigned getX() const { return x; }
    virtual char getChar() const { return PLAYER_CHAR; }
    /// player tries to take equipment (false if not enough space in the inventar)
    bool take(const HeroEquipment &) const;
    const String &getName() const { return name; }
    virtual void printStats() const = 0;
    /// print equipment of the hero
    void printItems() const;
    /// print player's info, battle icon and dragon's info
    void printBattleState(Dragon &) const;
    virtual bool alive() const = 0;
    /// deal damage to a dragon
    void hit(Dragon &d);
    virtual void takeDamage(float dmg) = 0;

    virtual void printBrief() const = 0;

    virtual float getAttack() const = 0;
    virtual float getHealth() const = 0;
    virtual float getMana() const = 0;

    virtual void regenerate(float percentage = 0) = 0;
    /// reset position on the board (back to top-left corner)
    void reset() { y = x = 0; }
    /// write info into text file
    void save(const String &game) const;

    virtual void gainXP(unsigned gain) = 0;
};

template <typename ALLOWED>
bool Player::move(bool &run, bool &pause, ALLOWED f)
{
    char c = getch();
    if (c == KEYS::UP && f(y - 1, x))
    {
        --y;
        return true;
    }
    else if (c == KEYS::DOWN && f(y + 1, x))
    {
        ++y;
        return true;
    }
    else if (c == KEYS::LEFT && f(y, x - 1))
    {
        --x;
        return true;
    }
    else if (c == KEYS::RIGHT && f(y, x + 1))
    {
        ++x;
        return true;
    }
    else if (c == 'i')
    {
        inventar();
        return true;
    }
    else if (c == 'p')
    {
        pause = true;
        return false;
    }
    return false;
}

#endif
#ifndef __PLAYER_HPP
#define __PLAYER_HPP
#include <conio.h>
#include <iostream>
#include "Inventar.hpp"
#include "Dragon.hpp"

enum class KEYS
{
    NONE = 0,
    UP = 'w',
    DOWN = 's',
    LEFT = 'a',
    RIGHT = 'd',
    EXIT = '`'
    // todo arrows
};

bool operator==(char c, const KEYS &k);

class Player
{
    static const char PLAYER_CHAR = (char)177;
    unsigned y, x;
    Inventar *inv;
    Printer lazy;
    String name;

    HeroEquipment *&getMatching(const HeroEquipment *ptr);
    void printInventar() const;
    void inventar();
    virtual bool payCost(float points) = 0;

protected:
    HeroEquipment *equip[Constants::EQUIPMENT_COUNT];

public:
    Player(unsigned posY, unsigned posX, const String &n);
    virtual ~Player();

    template <typename ALLOWED>
    bool move(bool &run, bool &pause, ALLOWED f);

    unsigned getY() const { return y; }
    unsigned getX() const { return x; }
    virtual char getChar() const { return PLAYER_CHAR; }
    bool take(const HeroEquipment &) const;
    const String &getName() const { return name; }
    virtual void printStats() const = 0;
    void printItems() const;
    void printBattleState(Dragon &) const;
    virtual bool alive() const = 0;

    void hit(Dragon &d);
    virtual void takeDamage(float dmg) = 0;

    virtual void printBrief() const = 0;

    virtual float getAttack() const = 0;
    virtual float getHealth() const = 0;
    virtual float getMana() const = 0;

    virtual void regenerate(float percentage = 0) = 0;

    void reset() { y = x = 0; }

    void save(const String &game) const;
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
    // else if (c == KEYS::EXIT)//todo should it be here
    //     return run = false;
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
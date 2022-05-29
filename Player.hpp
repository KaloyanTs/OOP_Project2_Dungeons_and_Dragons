#ifndef __PLAYER_HPP
#define __PLAYER_HPP
#include <conio.h>
#include <iostream>
#include "Inventar.hpp"

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
    Inventar inv;
    Weapon *w;
    Armor *a;
    Spell *sp;
    Printer lazy;

public:
    Player(unsigned posY, unsigned posX)
        : y(posY), x(posX),
          w(nullptr), a(nullptr), sp(nullptr) {}

    template <typename ALLOWED>
    bool move(bool &run, ALLOWED f);

    unsigned getY() const { return y; }
    unsigned getX() const { return x; }
    virtual char getChar() const { return PLAYER_CHAR; }
    bool take(const HeroEquipment &) const;
};

template <typename ALLOWED>
bool Player::move(bool &run, ALLOWED f)
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
    else if (c == KEYS::EXIT)
        return run = false;
    else if (c == 'i')
    {
        system("cls");
        inv.print(lazy);
        while (getch() != 'i')
        {
        }
        return true;
    }
    return false;
}

#endif
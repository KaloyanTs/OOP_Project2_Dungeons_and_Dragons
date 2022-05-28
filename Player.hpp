#ifndef __PLAYER_HPP
#define __PLAYER_HPP
#include <conio.h>
#include "iostream"

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
    unsigned y, x;

public:
    Player(unsigned posY, unsigned posX)
        : y(posY), x(posX) {}

    template <typename ALLOWED>
    bool move(bool &run, ALLOWED f);

    unsigned getY() const { return y; }
    unsigned getX() const { return x; }
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
    return false;
}

#endif
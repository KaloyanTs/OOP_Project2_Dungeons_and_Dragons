#ifndef __PLAYER_HPP
#define __PLAYER_HPP
#include <conio.h>
#include "iostream"

enum class KEYS
{
    NONE = 0,
    UP = 72,
    DOWN = 80,
    LEFT = 75,
    RIGHT = 77
};

bool operator==(char c, const KEYS &k);

class Player
{
    unsigned y, x;
    bool isArrow;
    unsigned limY, limX;

public:
    Player(unsigned posY, unsigned posX, unsigned maxY, unsigned maxX)
        : y(posY), x(posX), limY(maxY), limX(maxX) {}
    bool move();

    unsigned getY() const { return y; }
    unsigned getX() const { return x; }
};

#endif
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
    Inventar *inv;
    HeroEquipment *w;
    HeroEquipment *a;
    HeroEquipment *sp;
    Printer lazy;
    String name;

    HeroEquipment *&getMatching(const HeroEquipment *ptr);

public:
    Player(unsigned posY, unsigned posX, const String &n);
    virtual ~Player();

    template <typename ALLOWED>
    bool move(bool &run, ALLOWED f);

    unsigned getY() const { return y; }
    unsigned getX() const { return x; }
    virtual char getChar() const { return PLAYER_CHAR; }
    bool take(const HeroEquipment &) const;
    const String &getName() const { return name; }
    virtual void printStats(const Printer &p) const = 0;
    void printItems(const Printer &p) const;
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
        inv->print(lazy, name);
        lazy("\nTo equip an item enter its number in the list.\nIf slot is taken items will be swapped.\n");
        while ((c = getch()) != 'i')
        {
            if (c - '0' - 1 < inv->getCount() && c - '0' >= 1)
            {
                HeroEquipment *rem = inv->remove(c - '0' - 1);
                HeroEquipment *&tmp = getMatching(rem);

                HeroEquipment *buf = tmp;
                tmp = rem;
                rem = buf;

                if (rem)
                    inv->put(*rem);

                system("cls");
                inv->print(lazy, name);
                lazy("\nTo equip an item enter its number in the list.\nIf slot is taken items will be swapped.\n");
            }
        }
        return true;
    }
    else if (c == 'o')
    {
        system("cls");
        printStats(lazy);
        while (getch() != 'o')
        {
        }
        return true;
    }
    return false;
}

#endif
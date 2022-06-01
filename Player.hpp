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
    HeroEquipment *equip[Constants::EQUIPMENT_COUNT];
    Printer lazy;
    String name;

    HeroEquipment *&getMatching(const HeroEquipment *ptr);
    void printInventar() const;

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
    virtual void printStats() const = 0;
    void printItems() const;
    virtual bool alive() const = 0;

    void hit(Dragon &d) const;

    virtual void printBrief() const = 0;
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
        printInventar();
        while ((c = getch()) != 'i')
        {
            if (c == 'z' && inv->getCount())
            {
                Constants::STDOUT("\nPress z again to cancel...");
                while ((c = getch()) != 'z' && c - '0' < 1 && c - '0' - 1 >= inv->getCount())
                {
                }
                if (c != 'z')
                    delete inv->remove(c - '0' - 1);
                printInventar();
            }
            if (c == 'x')
            {
                Constants::STDOUT("\nPress x again to cancel...");
                while ((c = getch()) != 'x' && c - '0' < 1 && c - '0' - 1 >= Constants::EQUIPMENT_COUNT)
                {
                }
                if (c != 'x' && equip[c - '0' - 1])
                {
                    inv->put(*equip[c - '0' - 1]);
                    delete equip[c - '0' - 1];
                    equip[c - '0' - 1] = nullptr;
                }
                printInventar();
            }
            else if (c - '0' - 1 < inv->getCount() && c - '0' >= 1)
            {
                HeroEquipment *rem = inv->remove(c - '0' - 1);
                HeroEquipment *&tmp = getMatching(rem);

                HeroEquipment *buf = tmp;
                tmp = rem;
                rem = buf;

                if (rem)
                    inv->put(*rem);
                printInventar();
            }
        }
        return true;
    }
    return false;
}

#endif
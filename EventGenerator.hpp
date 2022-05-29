#ifndef __EVENT_GANERATOR_HPP
#define __EVENT_GANERATOR_HPP
#include <conio.h>
#include "MultipleImagePrinter.hpp"
#include "Player.hpp"

class EventGenerator
{
    unsigned posY, posX;
    bool onBoard = 0;

public:
    EventGenerator(unsigned y, unsigned x, unsigned board = true)
        : posY(y), posX(x), onBoard(board) {}
    virtual ~EventGenerator() {}

    virtual char getChar() const = 0;
    virtual bool action(Player *) = 0;
    virtual void print(const Printer &p) const = 0;
    bool locatedAt(unsigned y, unsigned x) { return posY == y && posX == x; }

    bool isOnBoard() const { return onBoard; }
};

#endif
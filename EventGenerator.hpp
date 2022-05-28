#ifndef __EVENT_GANERATOR_HPP
#define __EVENT_GANERATOR_HPP
#include "MultipleImagePrinter.hpp"

class EventGenerator
{
    unsigned posY, posX;

public:
    EventGenerator(unsigned y, unsigned x) : posY(y), posX(x) {}
    virtual char getChar() const = 0;
    virtual void print(const Printer &p) const = 0;
    bool locatedAt(unsigned y, unsigned x) { return posY == y && posX == x; }
};

#endif
#ifndef __EVENT_GANERATOR_HPP
#define __EVENT_GANERATOR_HPP
#include <conio.h>
#include "Constants.hpp"
#include "MultipleImagePrinter.hpp"

class Player;

class EventGenerator
{
    unsigned posY, posX;
    bool onBoard;

    const String *errorMsg;

protected:
    EventGenerator(unsigned y, unsigned x, unsigned board = true)
        : posY(y), posX(x), onBoard(board), errorMsg(nullptr) {}

public:
    EventGenerator(unsigned y, unsigned x, const String &msg, unsigned board = true)
        : posY(y), posX(x), onBoard(board), errorMsg(&msg) {}
    virtual ~EventGenerator() {}

    virtual char getChar() const = 0;
    virtual Constants::ACTION_STATE action(Player *, bool &run) = 0;
    virtual void print() const = 0;
    bool locatedAt(unsigned y, unsigned x) { return posY == y && posX == x; }

    bool isOnBoard() const { return onBoard; }
    void removeFromBoard() { onBoard = false; }

    unsigned getY() const { return posY; }
    unsigned getX() const { return posX; }

    const String &getErrorMsg() const { return *errorMsg; }

    virtual void write(std::ofstream &ofs) const = 0;
};

#endif
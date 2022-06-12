#ifndef __EVENT_GANERATOR_HPP
#define __EVENT_GANERATOR_HPP
#include <conio.h>
#include "Constants.hpp"
#include "MyException.hpp"

class Player;

/// abstract class representing something triggering an event
class EventGenerator
{
    unsigned posY, posX;
    bool onBoard;

    const String *errorMsg;

protected:
    /// construct event generator by its position on map
    EventGenerator(unsigned y, unsigned x, unsigned board = true)
        : posY(y), posX(x), onBoard(board), errorMsg(nullptr) {}

public:
    /// construct event generator by its position on map and error message
    EventGenerator(unsigned y, unsigned x, const String &msg, unsigned board = true)
        : posY(y), posX(x), onBoard(board), errorMsg(&msg) {}
    /// virtual destructor
    virtual ~EventGenerator() {}
    /// pure virtual function getting the representing character of the object on the map
    virtual char getChar() const = 0;
    /// function executing the action between the derived object and a player
    virtual Constants::ACTION_STATE action(Player *, bool &run) = 0;
    /// print info about the derived object
    virtual void print() const = 0;
    /// check if this object is located at particular position on the map
    bool locatedAt(unsigned y, unsigned x) { return posY == y && posX == x; }
    /// check if this generator in currently on the board
    bool isOnBoard() const { return onBoard; }
    void removeFromBoard() { onBoard = false; }
    unsigned getY() const { return posY; }
    unsigned getX() const { return posX; }
    const String &getErrorMsg() const
    {
        if (!errorMsg)
            throw MyException("no error message...", "const String &EventGenerator::getErrorMsg() const");
        return *errorMsg;
    }
    /// write the derived object info into a text file
    virtual void write(std::ofstream &ofs) const = 0;
};

#endif
#ifndef __MAP_HPP
#define __MAP_HPP
#include <iostream>
#include <ctime>
#include "Stack.hpp"
#include "Dragon.hpp"
#include "Player.hpp"
#include "MultipleImagePrinter.hpp"

enum class MAP_SYMBOLS
{
    FREE = '.',
    // WALL = '#',
    WALL = (char)219,
};

class Map
{
    unsigned rows, cols;
    unsigned level;
    char **data;
    size_t dragonCount;
    size_t treasureCount;
    Vector<EventGenerator *> events;
    Player *pl;
    const MultipleImagePrinter &p;
    bool running;

    void generateMap() const;

    size_t fib(unsigned lvl, unsigned val1, unsigned val2) const;
    bool isReachable(unsigned y, unsigned x) const;
    void print() const;

public:
    Map(const MultipleImagePrinter &print, unsigned lvl = 1);
    Map(const Map &other) = delete;
    Map &operator=(const Map &other) = delete;
    ~Map();
    void run();
};

#endif
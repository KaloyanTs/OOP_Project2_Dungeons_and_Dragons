#ifndef __MAP_HPP
#define __MAP_HPP
#include <iostream>
#include <ctime>
#include <stack> // fix
#include "Dragon.hpp"

enum class MAP_SYMBOLS
{
    FREE = '.',
    WALL = '#',
    MONSTER = 'M',
    TREASURE = 'T'
};

class Map
{
    unsigned rows, cols;
    unsigned level;
    char **data;
    size_t dragonCount;
    Dragon **dragons;

    void generateMap() const;

    size_t fib(unsigned lvl, unsigned val1, unsigned val2) const;

public:
    bool isReachable(unsigned y, unsigned x) const;
    Map(unsigned lvl = 1);
    Map(const Map &other) = delete;
    Map &operator=(const Map &other) = delete;
    ~Map();
    void print() const;
};

#endif
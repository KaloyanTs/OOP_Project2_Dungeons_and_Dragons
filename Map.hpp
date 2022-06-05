#ifndef __MAP_HPP
#define __MAP_HPP
#include <iostream>
#include <ctime>
#include <fstream>
#include "Constants.hpp"
#include "Human.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Dragon.hpp"

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
    size_t potionCount;
    Vector<EventGenerator *> events;
    Player *pl;
    bool running;

    void generateMap() const;

    size_t fib(unsigned lvl, unsigned val1, unsigned val2) const;
    bool isReachable(unsigned y, unsigned x) const;
    EventGenerator *print() const;

public:
    Map(Player *p, const String &path);
    Map(Player *p, unsigned lvl = 1);
    Map(const Map &other) = delete;
    Map &operator=(const Map &other) = delete;
    ~Map();
    Constants::LEVEL_STATE run();
    static Player *getHero(unsigned index, const String &name = "unknown");
};

#endif
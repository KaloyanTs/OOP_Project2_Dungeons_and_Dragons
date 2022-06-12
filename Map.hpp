#ifndef __MAP_HPP
#define __MAP_HPP
#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
#include "Constants.hpp"
#include "Human.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Dragon.hpp"
#include "MyException.hpp"

/// class representing the map of game
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
    bool pause;
    bool saved;

    void generateMap() const;

    size_t fib(unsigned lvl, unsigned val1, unsigned val2) const;
    bool isReachable(unsigned y, unsigned x) const;
    EventGenerator *print() const;

public:
    /// enum keeping the character for the free spots and walls on the map
    enum class MAP_SYMBOLS
    {
        FREE = '.',
        // WALL = '#',
        WALL = (char)219,
    };
    /// construct map by player and name of game to be read from file locted at directory "games\"
    Map(Player *p, const String &path);
    /// construct random map by player and level of the map
    Map(Player *p, unsigned lvl = 1);
    Map(const Map &other) = delete;
    Map &operator=(const Map &other) = delete;
    ~Map();
    /// run action on the map (player moves and does some action)
    Constants::LEVEL_STATE run();
    /// get Hero by ID and name
    static Player *getHero(unsigned index, const String &name = "unknown");
    /// check if current state of the map is saved
    bool isSaved() const { return saved; }
    /// save current state of the map on file "games\<game name>.dndmap"
    void saveProgress(const String &game);
    static Map *read(const String &file, Player *p);
    unsigned getLevel() const { return level; }
};

#endif
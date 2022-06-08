#ifndef __GAME_HPP
#define __GAME_HPP
#include "MultipleImagePrinter.hpp"
#include "Map.hpp"
#include <cstring>

class Game
{
    Map *map;
    Player *pl;
    bool running;
    unsigned level;

    void newGame();

    Constants::LEVEL_STATE run();

    void save();

    static Player *readPlayer(const String &file);

public:
    Game();
    ~Game()
    {
        delete map;
        delete pl;
    }

    void start();

    void load();
};

#endif
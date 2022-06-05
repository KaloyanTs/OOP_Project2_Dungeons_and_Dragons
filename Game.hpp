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

public:
    Game();
    ~Game()
    {
        delete map;
        delete pl;
    } // improve ask for saving

    void load();

    void newGame();

    Constants::LEVEL_STATE run();
};

#endif
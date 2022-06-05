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

public:
    Game();

    void load();

    void newGame();

    Constants::LEVEL_STATE run();
};

#endif
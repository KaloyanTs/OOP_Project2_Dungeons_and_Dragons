#ifndef __GAME_HPP
#define __GAME_HPP
#include "MultipleImagePrinter.hpp"
#include "Map.hpp"
#include <cstring>

class Game
{
    Map *map;
    Player *pl;

public:
    Game();

    bool run();
};

#endif
#ifndef __GAME_HPP
#define __GAME_HPP
#include "Map.hpp"
#include <cstring>

/// main class representing a dungeons and dragons game having map and player
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
    /// construct empty game
    Game();
    ~Game()
    {
        delete map;
        delete pl;
    }
    /// start a game; ends when player decides to stop playing
    void start();
    /// load existing game the user wants from directory "games\"
    void load();
};

#endif
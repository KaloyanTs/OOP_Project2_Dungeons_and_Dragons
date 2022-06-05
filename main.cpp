#include <iostream>
#include "Game.hpp"

int main()
{
    srand(time(0));
    Game dnd;
    dnd.newGame();
    dnd.run();

    return 0;
}
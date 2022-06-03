#include "Game.hpp"

Game::Game() : map(nullptr), pl(nullptr)
{
}

bool Game::run()
{
    Constants::STDOUT(GameAssets::game_logo);
    Constants::STDOUT("\tPress any key to play...");
    getch();
    system("cls");
    Constants::STDOUT("Choose a hero:\n\t1 for human\n\t2 for mage\n\t3 for warrior\n");
    char chosen;
    do
    {
        chosen = getch();
    } while (chosen - '0' - 1 >= Constants::HERO_TYPES || chosen - '0' - 1 < 0);
    char name[100]; // fix use String
    Constants::STDOUT("Choose name for your hero:\t");
    std::cin.getline(name, 100);
    if (!*name)
        strcpy(name, "unknown");
    pl = Map::getHero(chosen - '0' - 1, name);
    Map m(pl, 1);
    m.run();     // todo enum for the finish (DIE,SUCCESS,CLOSE)
                 // todo in while cycle until !=SUCCESS
    return true; // fix upper line
}

#include "Game.hpp"

Game::Game() : map(nullptr), pl(nullptr), running(false), level(0)
{
}

void Game::start()
{
    // todo enable Constants::STDOUT(GameAssets::game_logo);
    // todo enable Constants::STDOUT("\tPress any key to play...");
    getch();
    system("cls");
    Constants::STDOUT("Press l to load game or n to begin new game\n");
    char c;
    while ((c = getch()) != 'l' && c != 'n')
    {
    }
    try
    {
        if (c == 'l')
        {
            load(); // todo if not found throw exception
            // todo error handling
        }
        else
            newGame();
        Constants::LEVEL_STATE res = run();
    }
    catch (const char *msg)
    {
        return;
    } // fix use my own exception class
    // todo switch cases for res and print appropriate messages
}

void Game::load()
{
    // todo ask for name and search file
    // todo use exceptions
}

void Game::newGame()
{
    level = 1;
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
    map = new Map(pl, level);
}

Constants::LEVEL_STATE Game::run()
{
    if (running)
        return Constants::LEVEL_STATE::ERROR;
    Constants::LEVEL_STATE tmp;
    while (true)
    {
        std::cout << "Begin:\n";
        tmp = map->run();
        if (tmp == Constants::LEVEL_STATE::PASS)
        {
            delete map;
            map = new Map(pl, ++level);
            pl->reset();
        }
        else
        {
            running = false;
            return tmp;
        }
    }

    return Constants::LEVEL_STATE::ERROR;
    // todo enum for the finish (DIE,SUCCESS,CLOSE)
    // todo in while cycle until !=SUCCESS
    // return Constants::LEVEL_STATE::PASS; // fix upper line
}

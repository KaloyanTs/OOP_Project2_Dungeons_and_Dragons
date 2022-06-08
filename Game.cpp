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
    char name[Constants::INPUT_LIMIT];
    strcpy(name, "\\games\\");
    Constants::STDOUT("enter name of game to be loaded:\n");
    std::cin.getline(name + 7, Constants::INPUT_LIMIT);
    // fix use constants
    strcat(name, ".dndgame");
    std::ifstream ifs(name);
    if (!ifs)
        throw "ERROR!"; // fix use my exception
    char type;
    ifs >> type;
    // if (type == '1')
    //     pl = new Human(ifs);
    // if (type == '2')
    //     pl = new Mage(ifs);
    // if (type == '3')
    //     pl = new Warrior(ifs);
    // ifs >> name + 7; // fix use constants
    // strcat(name, ".dndmap");
    // map = new Map(pl, name);

    ifs.close();
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
    char name[Constants::INPUT_LIMIT]; // fix use String
    Constants::STDOUT("Choose name for your hero:\t");
    std::cin.getline(name, Constants::INPUT_LIMIT);
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

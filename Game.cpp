#include "Game.hpp"

Game::Game() : map(nullptr), pl(nullptr), running(false), level(0)
{
}

void Game::start()
{
    // todo enable Constants::STDOUT(GameAssets::game_logo);
    // todo enable Constants::STDOUT("\tPress any key to play...");
    // todo enable getch();
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
    strcpy(name, "games\\");
    Constants::STDOUT("enter name of game to be loaded:\n");
    std::cin.getline(name + 6, Constants::INPUT_LIMIT);
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
    // ifs >> name + 6; // fix use constants
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
    char name[Constants::INPUT_LIMIT] = "";
    Constants::STDOUT("Choose name for your hero:\t");
    std::cin.getline(name, Constants::INPUT_LIMIT);
    if (!*name)
        strcpy(name, "unknown");
    pl = Map::getHero(chosen - '0' - 1, name);
    map = new Map(pl, level); // todo this is throwing an exception
    // map = new Map(pl, "assets\\level4.dndmap");
}

Constants::LEVEL_STATE Game::run()
{
    if (running)
        return Constants::LEVEL_STATE::ERROR;
    Constants::LEVEL_STATE tmp;
    running = true;
    while (running)
    {
        tmp = map->run();
        if (tmp == Constants::LEVEL_STATE::PASS)
        {
            delete map;
            map = new Map(pl, ++level);
            pl->reset();
        }
        else if (tmp == Constants::LEVEL_STATE::PAUSE)
        {
            system("cls");

            char c;
            Constants::STDOUT("Press p to resume the game;\nPress s to save current progress;\nPress ` to exit.");
            while ((c = getch()) != 'p' && c != '`' && c != 's')
            {
            }
            if (c == KEYS::EXIT)
            {
                running = false;
                if (!map->isSaved())
                {
                    Constants::STDOUT("\n\ns to save your progress\nx to quit without saving\n");
                    char c;
                    while ((c = getch()) != 's' && c != 'x' && c != (char)KEYS::EXIT)
                    {
                    }
                    if (c == 's')
                        save();
                    else if (c == KEYS::EXIT)
                        running = true;
                }
            }
            else if (c == 's')
                save();
        }
        else
        {
            running = false;
            return tmp;
        }
    }

    return Constants::LEVEL_STATE::ERROR;
}

void Game::save()
{
    Constants::STDOUT("\n\nEnter name of current game: ");
    char name[Constants::INPUT_LIMIT];
    std::cin >> name;
    pl->save(name);
    map->saveProgress(name);
}

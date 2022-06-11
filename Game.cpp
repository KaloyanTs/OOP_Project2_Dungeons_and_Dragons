#include "Game.hpp"

Game::Game() : map(nullptr), pl(nullptr), running(false), level(0)
{
}

void Game::start()
{
    Constants::STDOUT(GameAssets::game_logo);
    Constants::STDOUT("\tPress any key to play...");
    getch();

    system("cls");
    delete map;
    delete pl;
    Constants::STDOUT("Press l to load game or n to begin new game\n");
    char c;
    while ((c = getch()) != 'l' && c != 'n')
    {
    }
    if (c == 'l')
    {
        try
        {
            load();
        }
        catch (const MyException &err)
        {
            delete pl;
            delete map;
            std::cerr << err.what() << '\n';
            getch();
            newGame();
        }
    }
    else
        newGame();
    Constants::LEVEL_STATE res = run();
    if (res == Constants::LEVEL_STATE::ERROR)
        std::cerr << "Unexpected error occured...\n";
}

void Game::load()
{
    // throw MyException("Temporarily disabled", "Player *readPlayer(const String &)");

    char name[Constants::INPUT_LIMIT];
    Constants::STDOUT("enter name of game to be loaded:\n");
    std::cin.getline(name, Constants::INPUT_LIMIT);
    pl = Game::readPlayer(name);
    map = new Map(pl, name);
}

Player *Game::readPlayer(const String &file)
{
    String path = "games\\";
    (path += file) += ".dndplayer";
    std::ifstream ifs(path);
    if (!ifs)
        throw MyException(path + " NOT FOUND...", "Player *readPlayer(const String &)");
    int type;
    ifs >> type;
    Player *res = nullptr;
    if (type == (int)Player::HERO_TYPE::HUMAN)
        res = new Human(ifs);
    if (type == (int)Player::HERO_TYPE::MAGE)
        res = new Mage(ifs);
    if (type == (int)Player::HERO_TYPE::WARRIOR)
        res = new Warrior(ifs);
    else
        throw MyException("FAILED TO DETERMINE HERO TYPE...", "Player *readPlayer(const String &)");
    return res;
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
            if (level < LEVEL_COUNT)
            {
                delete map;
                map = new Map(pl, ++level);
                pl->reset();
            }
            else
            {
                Constants::STDOUT(pl->getName())(", you proved yourself as a real hero and will be rewarded as deserved!\nThis is the end game...");
                running = false;
                return Constants::LEVEL_STATE::END;
            }
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

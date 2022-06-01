#include <iostream>
#include "MultipleImagePrinter.hpp"
#include "Map.hpp"
#include <cstring>

int main()
{
    srand(time(0));
    Image logo("assets\\logo.dnd");
    Constants::STDOUT(logo);
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
    MultipleImagePrinter p;
    Map m(p, Map::getHero(chosen - '0' - 1, name), 4);
    // fix Map m(p, "assets\\level4.dndmap");

    m.run();

    return 0;
}
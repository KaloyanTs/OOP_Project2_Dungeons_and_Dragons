#include <iostream>
#include "Image.hpp"
#include "MultipleImagePrinter.hpp"
#include "Dragon.hpp"
#include "Map.hpp"
#include "Player.hpp"

int main()
{
    srand(time(0));
    Image logo("assets\\logo.dnd");
    Printer out;
    out(logo);
    out("\tPress any key to play...");
    getch();
    system("cls");
    std::cout << "Choose a hero:\n\t1 for human\n\t2 for mage\n\t3 for warrior\n";
    char chosen;
    do
    {
        chosen = getch();
    } while (chosen - '0' >= Constants::HERO_TYPES || chosen - '0' < 0);
    char name[100]; // fix use String
    std::cout << "Choose name for your hero:\t";
    std::cin.getline(name, 100);
    MultipleImagePrinter p;
    Map m(p, Map::getHero(chosen - '0', name), 4);
    // fix Map m(p, "assets\\level4.dndmap");

    m.run();

    return 0;
}
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
    getch();
    // std::cin.get();
    MultipleImagePrinter p;
    Map m(p, 4);
    // fix Map m(p, "assets\\level4.dndmap");

    m.run();

    return 0;
}
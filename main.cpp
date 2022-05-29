#include <iostream>
#include "Image.hpp"
#include "MultipleImagePrinter.hpp"
#include "Dragon.hpp"
#include "Map.hpp"
#include "Player.hpp"

int main()
{
    Image logo("assets\\logo.dnd");
    Printer out;
    out(logo);
    getch();
    // Dragon lamb;
    //  fix lamb.print(mOut);
    // std::cin.get();
    MultipleImagePrinter p;
    Map m(p, 4);
    //fix Map m(p, "assets\\level4.dndmap");
    m.run();
    return 0;
}
#include <iostream>
#include "Image.hpp"
#include "MultipleImagePrinter.hpp"
#include "Dragon.hpp"
#include "Map.hpp"
#include "Player.hpp"

int main()
{
    // Image logo("assets\\logo.dnd");
    // Printer out;
    //  out(logo);
    // Dragon lamb;
    //  fix lamb.print(mOut);
    // std::cin.get();
    Map m;
    m.print();
    // std::cin.get();
    std::cout << m.isReachable(9, 9);
    Player p(0,0);
    p.move();
    p.move();
    p.move();
    p.move();
    p.move();
    p.move();
    return 0;
}
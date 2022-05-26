#include <iostream>
#include "Image.hpp"
#include "Printer.hpp"

int main()
{
    Image logo("assets\\logo.dnd");
    Printer out;
    out(logo);
    std::cin.get();
    return 0;
}
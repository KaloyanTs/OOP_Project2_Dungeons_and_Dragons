#include <iostream>
#include "Image.hpp"
#include "MultipleImagePrinter.hpp"

int main()
{
    Image logo("assets\\logo.dnd");
    Image dragon7("assets\\dragon7.dnd");
    Image dragon8("assets\\dragon8.dnd");
    Image *dragons[] = {&dragon7, &dragon8};
    Printer out;
    out(logo);
    MultipleImagePrinter mOut;
    mOut(dragons, 2, 10);
    std::cin.get();
    return 0;
}
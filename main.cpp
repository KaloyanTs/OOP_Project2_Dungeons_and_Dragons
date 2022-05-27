#include <iostream>
#include "Image.hpp"
#include "MultipleImagePrinter.hpp"

int main()
{
    Image logo("assets\\logo.dnd");
    Image dragon1("assets\\dragon1.dnd");
    Image dragon2("assets\\dragon9.dnd");
    Image *dragons[] = {&dragon1, &dragon2};
    Printer out;
    out(logo);
    MultipleImagePrinter mOut;
    mOut(dragons, 2, 10);
    std::cin.get();
    Image heartArr[] =
        {
            Image("assets\\health.dnd"),
            Image("assets\\weapon.dnd"),
            Image("assets\\spell.dnd")};
    Image *hearts[] =
        {
            &heartArr[0],
            &heartArr[1],
            &heartArr[2]};

    mOut(hearts, 3, 5);
    std::cin.get();
    return 0;
}
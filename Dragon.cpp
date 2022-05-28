#include "Dragon.hpp"

void Dragon::print(const Printer &p) const
{
    p(*pic);
    p("Dragon ")(level)(".lvl\n");
    Troop::print(p);
}
#include "Dragon.hpp"

 void Dragon::print(const Printer &p) const
{
    p(*pic);
    Troop::print(p);
}
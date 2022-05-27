#include "Dragon.hpp"

 void Dragon::print(const MultipleImagePrinter &p) const
{
    ((const Printer &)p)(*pic);
    Troop::print(p);
}
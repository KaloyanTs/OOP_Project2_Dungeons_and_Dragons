#ifndef __Printer_HPP
#define __Printer_HPP
#include <iostream>

class Printer
{
    std::ostream &os;

public:
    Printer(std::ostream &_os = std::cout) : os(_os) {}
    template <typename Printable>
    Printer &operator()(const Printable &p)
    {
        os << p << '\n';
        return *this;
    }
};

#endif
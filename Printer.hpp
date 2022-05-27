#ifndef __Printer_HPP
#define __Printer_HPP
#include <iostream>

class Printer
{
    std::ostream &os;

protected:
    std::ostream &getOutputStream() const { return os; }

public:
    Printer(std::ostream &_os = std::cout) : os(_os) {}
    template <typename Printable>
    const Printer &operator()(const Printable &p) const
    {
        os << p;
        return *this;
    }
};

#endif
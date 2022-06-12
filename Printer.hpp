#ifndef __Printer_HPP
#define __Printer_HPP
#include <iostream>
#include <iomanip>
#include "GameAssets.hpp"

/// class representing printer for all kind of things
class Printer
{
    std::ostream &os;

protected:
    std::ostream &getOutputStream() const { return os; }

public:
    Printer(std::ostream &_os = std::cout) : os(_os) { os << std::setprecision(2) << std::fixed; }
    /// print something to the output stream
    template <typename Printable>
    const Printer &operator()(const Printable &p) const
    {
        os << p;
        return *this;
    }
};

#endif
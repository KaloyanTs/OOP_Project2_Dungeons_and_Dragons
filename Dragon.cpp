#include "Dragon.hpp"

String Dragon::errorMsg = "You could not stand a chance against this dragon but you fought bravely and died...\n";

void Dragon::print() const
{
    Constants::STDOUT (*pic)("Dragon ")(getLevel())(".lvl\n")("\t - ")(quote)('\n');
    Troop::print();
}

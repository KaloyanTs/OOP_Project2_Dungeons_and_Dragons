#ifndef __DRAGON_HPP
#define __DRAGON_HPP
#include "Troop.hpp"

class Dragon : public Troop
{
    unsigned level;
    const Image *pic;
    unsigned posY, posX;

public:
    Dragon(unsigned y, unsigned x) : Troop(25, 25, 50), level(1), pic(&GameAssets::dragon), posY(y), posX(x)
    {
    }
    virtual Dragon *clone() const { return new Dragon(*this); }
    virtual void print(const MultipleImagePrinter &p) const;
};

#endif
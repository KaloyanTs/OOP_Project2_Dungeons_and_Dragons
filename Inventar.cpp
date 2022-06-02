#include "Inventar.hpp"

EventGenerator *Inventar::getEquipment(unsigned index, unsigned y, unsigned x, unsigned bot, unsigned top)
{
    if (!index)
        return new Weapon(y, x, bot, top);
    else if (index == 1)
        return new Armor(y, x, bot, top);
    else if (index == 2)
        return new Spell(y, x, bot, top);
    return nullptr;
}

void Inventar::print(const String &owner) const
{
    Constants::STDOUT(owner)("'s inventar:\n\n");
    for (unsigned i = 0; i < m_size; ++i)
        this->operator[](i)->print();
}

bool Inventar::put(const HeroEquipment &el)
{
    if (m_size < limit)
    {
        push_back(el.clone());
        return true;
    }
    return false; // todo info to clog about the operation
}

Inventar::~Inventar()
{
    HeroEquipment *ptr;
    while (!empty())
    {
        ptr = pop_back();
        delete ptr;
    }
}

HeroEquipment *Inventar::remove(unsigned index)
{
    return pop_at(index);
}
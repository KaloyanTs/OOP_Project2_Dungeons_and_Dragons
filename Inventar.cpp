#include "Inventar.hpp"

EventGenerator *Inventar::getEquipment(unsigned index, unsigned y, unsigned x, unsigned bot, unsigned top, unsigned cost)
{
    if (!index)
        return new Weapon(y, x, bot, top);
    else if (index == 1)
        return new Armor(y, x, bot, top);
    else if (index == 2)
        return new Spell(y, x, bot, top, true, cost);
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
    return false;
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

void Inventar::write(std::ofstream &ofs) const
{
    ofs << m_size << '\n';
    for (unsigned i = 0; i < m_size; ++i)
    {
        if (data[i])
            data[i]->save(ofs);
    }
}

HeroEquipment *Inventar::readEquipment(std::ifstream &ifs, unsigned buf)
{
    // ofs << (int)getID() << ' ' << getBonus() << getCost() << ' '
    //         << name.size() << ' ' << name.c_str() << '\n';
    unsigned bonus;
    float cost;
    unsigned length;
    ifs >> cost >> bonus >> length;
    ifs.ignore();
    char *name = new char[length + 1];
    ifs.getline(name, length + 1);
    HeroEquipment *res = nullptr;
    if (buf == (unsigned)HeroEquipment::ID::ARMOR)
        res = new Armor(bonus, name);
    else if (buf == (unsigned)HeroEquipment::ID::POTION)
        res = new Potion(bonus, name);
    else if (buf == (int)HeroEquipment::ID::WEAPON)
        res = new Weapon(bonus, name);
    else if (buf == (int)HeroEquipment::ID::SPELL)
        res = new Spell(bonus, cost, name);

    delete[] name;
    return res;
}
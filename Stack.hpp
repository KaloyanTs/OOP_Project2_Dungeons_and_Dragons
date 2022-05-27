#ifndef __STACK_HPP
#define __STACK_HPP
#include "Vector.hpp"
#include <cassert>

template <typename T>
class Stack : protected Vector<T>
{
public:
    T top()const
    {
        //todo in cpp
        assert(size);
        return data[size - 1];
    }
    Stack &push(const T &el)
    {
        //todo in cpp
        push_back(el);
        return *this;
    }
    void pop()
    {
        //todo in cpp
    }
};

#endif
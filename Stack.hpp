#ifndef __STACK_HPP
#define __STACK_HPP
#include "Vector.hpp"
#include <cassert>

template <typename T>
class Stack : protected Vector<T>
{
public:
    T top() const;
    Stack &push(const T &el);
    void pop();
    bool empty() const { return !Vector<T>::m_size; }
};

template <typename T>
T Stack<T>::top() const
{
    assert(Vector<T>::m_size);
    return Vector<T>::data[Vector<T>::m_size - 1];
}

template <typename T>
Stack<T> &Stack<T>::push(const T &el)
{
    Vector<T>::push_back(el);
    return *this;
}

template <typename T>
void Stack<T>::pop()
{
    --Vector<T>::m_size;
    if (Vector<T>::m_capacity > Vector<T>::INIT_CAPACITY &&
        (Vector<T>::m_size << 1) <= Vector<T>::m_capacity)
        Vector<T>::shrink();
}

#endif
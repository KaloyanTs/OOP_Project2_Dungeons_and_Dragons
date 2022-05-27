#ifndef __VECTOR_HPP
#define __VECTOR_HPP
#include <cstddef>

template <typename T>
class Vector
{
    static const unsigned INIT_CAPACITY = 2;
    T *data;
    size_t size, capacity;

    void expand();
    void shrink();
    void copy(const Vector &other);

public:
    Vector(size_t cap = INIT_CAPACITY) : data(new T[cap]), capacity(cap), size(0) {}
    Vector(const Vector &other);
    Vector &operator=(const Vector &other);
    ~Vector();

    unsigned getCount() const { return size; }
    Vector &push_back(const T &el);
};

template <typename T>
void Vector<T>::expand()
{
    capacity <<= 1;
    T *newData = new T[capacity];
    for (unsigned i = 0; i < size; ++i)
        newData[i] = data[i];
    delete[] data;
    data = newData;
}

template <typename T>
void Vector<T>::shrink()
{
    capacity >>= 1;
    T *newData = new T[capacity];
    for (unsigned i = 0; i < size; ++i)
        newData[i] = data[i];
    delete[] data;
    data = newData;
}

template <typename T>
void Vector<T>::copy(const Vector &other)
{
    clear();
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (unsigned i = 0; i < size; ++i)
        data[i] = other.data[i];
}

template <typename T>
Vector<T>::Vector(const Vector &other)
    : data(nullptr), size(0)
{
    copy(other);
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}

template <typename T>
Vector<T> &Vector<T>::push_back(const T &el)
{
    if (size == capacity)
        expand();
    data[size++] = el;
    return *this;
}

#endif
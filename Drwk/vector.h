#pragma once

#include "collection.h"
#include "Iterable.h"

namespace Drwk
{
template <typename T>
class Vector : public Collection<T>, public Itterable<T>
{
public:
    Vector() : m_data(nullptr), m_size(0) {}
    ~Vector();

    void push(T);
    T pop();
    int size() { return m_size; }

private:
    T *m_data;
    int m_size;
};

// Iterator
template <typename T>
class Vectorterator : Iterator<T>
{
    virtual next() override { data++; }
};

// Definitions
template <typename T>
Vector<T>::~Vector<T>()
{
    delete[] m_data;
}

template <typename T>
void Vector<T>::push(T value)
{
    if (m_size == 0)
    {
        m_data = new T[1];
        m_data[0] = T;
    }
    else
    {
    }
}
} // namespace Drwk

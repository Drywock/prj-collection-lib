#pragma once

#include "collection.h"
#include "Iterable.h"

namespace Drwk {
    template <typename T>
    class Vector : public Collection<T>, public Itterable<T>
    {
    public:
        Vector(): data(new T[1]) {}
        ~Vector();

        void push(T&);
        void pop();
        
    private:
        T* data;
    };

    template <typename T>
    class Vectorterator : Iterator<T>
    {
        
    };

    template <typename T>
    Vector<T>::~Vector<T>() {
        delete[] m_data;
    }
}

#pragma once

namespace Drwk {

    template <typename T>
	class Iterator
	{
	public:
        // Constructor
        Iterator(T* value) : m_value(value) {}

        // Methods
		virtual T& value(void) { return *m_value};
		virtual void next() = 0;

    // Operators
        friend bool operator!=(const Iterator<T> &a, const Iterator<T> &b);
        friend bool operator==(const Iterator<T> &a, const Iterator<T> &b);

        void operator++();
        void operator+=(const int& n);
        friend Iterator<T> operator+(Iterator<T> a, const int &n);
	private:
		T* m_value;
	};

	template <typename T>
	class Iterable
	{
	public:
		Iterator<T> begin();
		Iterator<T> end();
		void forEach(void (*func)(T&));

	private:
		Iterator<T> m_begin;
		Iterator<T> m_end;
	};

    // Iterrator methods definitions

    template<typename T>
    bool operator==(const Iterator<T> &a, const Iterator<T> &b)
    { 
        return a.m_value == b.m_value;
    }

    template<typename T>
    bool operator!=(const Iterator<T> &a, const Iterator<T> &b)
    { 
        return !(a == other);
    }

    template<typename T>
    void Iterator<T>::operator++()
    {
        next();
    }

    template<typename T>
    void Iterator<T>::operator+=(const int& n)
    {
        for(int i = 0; i < n; i++) *this++;
    }

    template<typename T>
    Iterator<T> operator+(Iterator<T> a, const int &n)
    {
        return a+= n;
    }

    // Iterable methods definitions
    
    template <typename T>
    void Iterable<T>::forEach(void (*func)(T&))
    {
        Iterator<T> iterator = m_begin;
        while (iterator != m_end)
        {
            func(iterator.value());
        }
    }
}

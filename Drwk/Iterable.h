#pragma once

namespace Drwk
{

template <typename T>
class Iterable;

template <typename T>
class Iterator
{
public:
	// Constructor
	Iterator(T *value) : m_value(value) {}

	// Methods
	virtual T &value(void) { return *m_value; }
	virtual void next() = 0;

	// Operators
	void operator++();
	void operator+=(const int &n);

protected:
	void setValue(T *value) { this->m_value = value; }
	friend class Iterable<T>;
	T *m_value;
};

template <typename T>
class Iterable
{
public:
	Iterable(Iterator<T> *begin, Iterator<T> *end) : m_begin(begin), m_end(end) {}
	Iterator<T> *begin() { return m_begin; }
	Iterator<T> *end() { return m_end; }
	void forEach(void (*func)(T &));

protected:
	Iterator<T> *m_begin;
	Iterator<T> *m_end;
	void setBeginValue(T *value) { m_begin->setValue(value); }
	void setEndValue(T *value) { m_end->setValue(value); }
};

// Iterrator methods definitions

template <typename T>
bool operator==(const Iterator<T> &a, const Iterator<T> &b)
{
	return a.value() == b.m_value();
}

template <typename T>
bool operator!=(const Iterator<T> &a, const Iterator<T> &b)
{
	return !(a == b);
}

template <typename T>
void Iterator<T>::operator++()
{
	next();
}

template <typename T>
void Iterator<T>::operator+=(const int &n)
{
	for (int i = 0; i < n; i++)
		*this ++;
}

template <typename T>
Iterator<T> operator+(Iterator<T> a, const int &n)
{
	return a += n;
}

// Iterable methods definitions

template <typename T>
void Iterable<T>::forEach(void (*func)(T &))
{
	Iterator<T> iterator = m_begin;
	while (iterator != m_end)
	{
		func(iterator.value());
	}
}
} // namespace Drwk

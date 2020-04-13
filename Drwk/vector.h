#pragma once

#include <cstring>

#include "collection.h"
#include "Iterable.h"

namespace Drwk
{

template <typename T>
class VectorIterator;

template <typename T>
class Vector : public Collection<T>, public Iterable<T>
{
public:
	Vector() : Iterable<T>(new VectorIterator<T>, new VectorIterator<T>()), m_data(nullptr), m_size(0) {}
	~Vector();

	void push(T);
	T pop();
	T &at(const int &index);
	void remove(const int &index);
	int size() { return m_size; }

private:
	T *m_data;
	int m_size;
};

// Iterator
template <typename T>
class VectorIterator : public Iterator<T>
{
public:
	VectorIterator() : Iterator<T>(nullptr) {}
	virtual void next() override { this->m_value++; }
};

// Definitions
template <typename T>
Vector<T>::~Vector<T>()
{
	if (m_data)
		delete[] m_data;
}

template <typename T>
void Vector<T>::push(T value)
{
	m_size++;
	m_data = reinterpret_cast<T *>(realloc(m_data, sizeof(T) * m_size));
	m_data[m_size - 1] = value;
	this->setBeginValue(&m_data[0]);
	this->setEndValue(&m_data[m_size - 1]);
}

template <typename T>
T Vector<T>::pop(void)
{
	m_size--;
	T value = m_data[m_size];
	m_data = reinterpret_cast<T *>(realloc(m_data, sizeof(T) * m_size));
	this->setBeginValue(&m_data[0]);
	this->setEndValue(&m_data[m_size - 1]);
	return value;
}

template <typename T>
T &Vector<T>::at(const int &index)
{
	if (index >= m_size)
		throw new std::out_of_range("Index out of bounds");
	return *(m_data + index);
}

template <typename T>
void Vector<T>::remove(const int &index)
{
	memmove(&m_data[index], &m_data[index + 1], sizeof(T) * (m_size - index));
	m_size--;
	m_data = reinterpret_cast<T *>(realloc(m_data, sizeof(T) * m_size));
	this->setBeginValue(&m_data[0]);
	this->setEndValue(&m_data[m_size - 1]);
}
} // namespace Drwk

#pragma once

#include "collection.h"

namespace Drwk
{

template <typename T>
class List : public Collection<T>
{
private:
	struct ListItem
	{
		T *m_data;
		List<T> *m_next;
	};
	ListItem *m_first;

	void append(T value);

	virtual int size(void) override;

public:
	List(/* args */);
	~List();
};

template <typename T>
List<T>::List(/* args */) : m_first(nullptr)
{
}

template <typename T>
List<T>::~List()
{
	delete m_data;
	delete m_next;
}

template <typename T>
void List<T>::append(T value)
{
	if (!m_first)
	{
		m_first = new ListItem({new T(value), nullptr});
	}
	else
	{
		ListItem *item = m_first;
		while (item->m_next)
		{
			item = item->m_next;
		}
		item->m_next = new ListItem({new T(value), nullptr})
	}
}

template <typename T>
int List<T>::size(void)
{
	if (!m_first)
		return 0;
	else
	{
		int count = 1;
		ListItem *item = m_first;
		while (item->m_next)
		{
			count++;
			item = item->m_next;
		}

		return count;
	}
}
} // namespace Drwk

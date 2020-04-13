#pragma once

namespace Drwk {

	template <typename T>
	class Collection
	{
	public:
		virtual int size() = 0;
	};


	template <typename T>
	class Itterator
	{
	public:
		virtual const T& value(void) { return m_value};
		virtual Itterator<T> next() = 0;
	private:
		T& m_value;
	};

	template <typename T>
	class Itterable
	{
	public:
		Itterator<T> begin();
		Itterator<T> end();
		forEach(void (*func)(T&));

	private:
		Itterator<T> m_begin;
		Itterator<T> m_end;
	};
}

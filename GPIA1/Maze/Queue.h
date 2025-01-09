#pragma once
#include "Vector.h"

template <typename T>
class Queue
{
public:
	Queue()
	{
		_container.resize(100);
	}

	void push(const T& value)
	{
		if (_size == _container.size())
		{
			
		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size();
		_size++;
	}

	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

private:
	Vector<T> _container;

	int _front = 0;
	int _back = 0;
	int _size = 0;
};


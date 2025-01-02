#pragma once
#include <assert.h>

class Vector
{
	using T = int;

public:
	explicit Vector()
	{
		
	}

	~Vector()
	{
		if(_buffer)
			delete[] _buffer;
	}

	void clear()
	{
		if (_buffer)
		{
			delete[] _buffer;
			_buffer = new T[_capacity];
		}

		_size = 0;
	}

	void push_back(const T& data)
	{
		if (_size == _capacity)
		{
			int newCapacity = static_cast<int>(_capacity*1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		_buffer[_size] = data;
		_size++;
	}

	void pop_back()
	{
		_size--;
	}

	T& back()
	{
		return _buffer[_size - 1];
	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity)
			return;

		_capacity = capacity;

		T* newData = new T[_capacity];

		for (int i = 0; i < _size; ++i)
			newData[i] = _buffer[i];

		if (_buffer)
			delete[] _buffer;

		_buffer = newData;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < _size);
		return _buffer[index];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T* _buffer = nullptr;
	int _size = 0;
	int _capacity = 0;
};


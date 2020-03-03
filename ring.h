#pragma once
#include <iostream>

template<class T>
class ring
{

private:
	uint16_t siz;
	uint16_t capacity;
	uint16_t index;
	T* elements;

public:
	class iterator;

	ring(const ring& other_ring)
	{
		this->siz = other_ring.siz;
		this->capacity = other_ring.capacity;
		this->index = other_ring.index;
		this->elements = other_ring.elements;
	}

	ring() : siz(0), index(0), capacity(0) {}

	ring(uint16_t siz)
	{
		this->index = 0;
		this->capacity = 0;
		this->siz = siz;
		this->elements = nullptr;
		this->elements = new T[this->siz];
	}


	T& repl(int16_t x)
	{
		return this->elements[x];
	}

	void add(T dat)
	{
		try
		{
			if (this->siz > 0)
			{
				if (this->index != this->siz)
				{
					this->elements[index] = dat;
					++this->index;
					++this->capacity;
				}

				else
				{
					this->index = 0;
					this->elements[index] = dat;
				}
			}

			else
			{
				throw std::runtime_error("no capacity");
			}

		}

		catch (std::runtime_error err)
		{
			std::cerr << err.what() << std::endl;
		}
	} ///

	T& get_pos(uint16_t pos)
	{
		return this->elements[pos];
	}

	iterator begin()
	{
		return iterator(0, *this);
	}

	iterator end()
	{
		return iterator(this->capacity, *this);
	}

	~ring()
	{
		this->elements = nullptr;
		delete[] this->elements;
	}

};

///......................................................................

template<class T>
class ring<T>::iterator
{

private:
	uint16_t pos;
	ring aring;

public:

	iterator(const iterator& other)
	{
		this = other;
	}

	iterator() : pos(0), aring(0) {}

	iterator(uint16_t mpos, ring& rin) : pos(mpos), aring(rin) {}

	T& operator*()
	{
		return this->aring.get_pos(pos);
	}

	iterator& operator++()
	{
		this->pos++;
		return *this;
	}

	iterator& operator++(int)
	{
		++pos;
		return *this;
	}

	T& operator[](int16_t x)
	{
		return this->aring.repl(x);
	}

	bool operator!=(const iterator& other) const
	{
		return this->pos != other.pos;
	}

	bool operator>(const iterator& other) const
	{
		return this->pos > other.pos;
	}

	bool operator<(const iterator& other) const
	{
		return this->pos < other.pos;
	}

};
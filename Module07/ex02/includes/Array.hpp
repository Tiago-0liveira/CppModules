#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <stdexcept>

template < typename T >
class Array
{
public:
    Array(): _size(0)
	{
		arr = new T[_size];
	}
    Array(unsigned int n): _size(n)
	{
        arr = new T[_size];
    };
    ~Array()
	{
		if (arr != NULL)
            delete[] arr;
    }
    Array(const Array& copy) : _size(copy.size())
	{
		arr = NULL;
        *this = copy;
    }
    Array& operator=(Array const & rhs)
	{
        if (this == &rhs)
            return *this;
		if (arr != NULL)
			delete[] arr;
		
		_size = rhs.size();
		arr = new T[_size];
		
		if (_size == 0)
			return *this;
		
		for (unsigned int i = 0; i < _size; i++)
			arr[i] = rhs[i];
		
        return *this;
    }
    T& operator[](unsigned int i) const
	{
        if (i >= _size || _size == 0)
        {
          throw std::out_of_range("Index out of range");
		}
		if (arr == NULL)
			throw std::exception();
        return arr[i];
    }
    T* getRawArray() const
	{
        return arr;
    };
    size_t size() const
	{
        return _size;
    }
private:
    T*          arr;
    size_t    _size;
};

#endif // ITER_HPP
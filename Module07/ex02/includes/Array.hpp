#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <stdexcept>

template < typename T >
class Array {
public:
    Array(): arr(NULL), _size() {}
    explicit Array(size_t n): _size(n) {
        if (n == 0)
            arr = NULL;
        else
            arr = new T[n];
    };
    ~Array() {
        delete[] arr;
    }
    Array(const Array& copy) : _size(copy.size()) {
        arr = new T[copy.size()];
        *this = copy;
    }
    Array& operator=(Array const & rhs) {
        if (this == &rhs)
            return *this;
        *arr = *rhs.getRawArray();
        return *this;
    }
    T& operator[](size_t i) {
        if (i >= _size)
          throw std::out_of_range("Index out of bounds");
        return arr[i];
    }
    void *operator new[](size_t n)
    {
        return new Array<T>(n);
    }
    T* getRawArray() const {
        return arr;
    };
    size_t size() const {
        return _size;
    }
private:
    T*      arr;
    size_t    _size;
};

#endif // ITER_HPP
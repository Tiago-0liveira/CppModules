#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <stdexcept>

typedef unsigned int uint;

template < typename T >
class Array {
public:
    Array(): arr(NULL), size() {}
    Array(uint n): size(n) {
        if (n == 0)
            arr = NULL;
        else
            arr = new T[n];
    };
    ~Array() {
        delete[] arr;
    }
    Array(const Array& copy) : size(copy.getSize()) {
        arr = new T[copy.getSize()];
        *this = copy;
    }
    Array& operator=(const Array& rhs) {
        if (this == &rhs)
            return *this;
        *arr = *rhs.getRawArray();
        return *this;
    }
    T& operator[](uint i) {
        if (i >= size)
          throw std::out_of_range("Index out of bounds");
        return arr[i];
    }
    T* getRawArray() {
        return arr;
    };
    uint getSize() {
        return size;
    }
private:
    T*      arr;
    uint    size;
};

#endif // ITER_HPP
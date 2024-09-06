#ifndef ITER_HPP
#define ITER_HPP

typedef unsigned int uint;

template<typename T>
void    iter(T* array, uint len, void (*func)(T &element)) {
    if (array == NULL || func == NULL || len == 0)
        return ;
    for (uint i = 0; i < len; i++) {
        func(array[i]);
    }
}

#endif // ITER_HPP
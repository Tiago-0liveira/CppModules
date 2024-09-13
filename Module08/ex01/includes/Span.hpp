#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
public:
    Span(unsigned int N);
    ~Span();
    Span(const Span& cpy);
    Span &operator=(const Span &rhs);

    void addNumber(int n) throw();

    size_t shortestSpan()  throw();
    size_t longestSpan() throw();

    // Getters
    const unsigned int getCapacity() const;
private:
    const unsigned int capacity;
    int const *arr;
};

#endif // SPAN_HPP
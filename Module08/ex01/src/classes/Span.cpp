#include <Span.hpp>

Span::Span(unsigned int N): capacity(N) 
{
    arr = new int[N];
}

Span::~Span() 
{
    if (arr)
        delete[] arr;
}

Span::Span(const Span &rhs): capacity(rhs.getCapacity())
{
    if (arr)
    {
        delete[] arr;
        arr = NULL;
    }
    *this = rhs;
}

Span &Span::operator=(const Span &rhs)
{
    if (this != &rhs)
    {
        if (arr)
        {
            delete[] arr;
            arr = new int[capacity];
        }
        // TODO: finnish this
    }
    return *this;
}

const unsigned int Span::getCapacity() const
{
    return capacity;
}
#include <Data.hpp>

Data::~Data() {}

Data::Data(int x, int y): x(x), y(y) {}

Data::Data(const Data &copy)
{
    *this = copy;
}

Data &Data::operator=(Data const & rhs)
{
    if (this != &rhs)
    {
        x = rhs.x;
        y = rhs.y;
    }
    return *this;
}
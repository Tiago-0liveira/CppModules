#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <cstdint>
#include <Data.hpp>

class Data
{/* Imagine data as 2d Point */
public:
	Data(int x, int y);
	Data(const Data & copy);
	Data &operator=(Data const & rhs);
	~Data();

    int x,y;
};

#endif // DATA_HPP
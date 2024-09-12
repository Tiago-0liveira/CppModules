#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data/* Point2D */
{
	Data(int x, int y): x(x), y(y) {}
	int x,y;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer & copy);
	Serializer &operator=(Serializer const & rhs);
public:
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
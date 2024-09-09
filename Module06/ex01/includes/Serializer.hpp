#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <Data.hpp>

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
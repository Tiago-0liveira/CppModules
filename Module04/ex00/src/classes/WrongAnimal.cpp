#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal(): type("wrong undefined")
{
	std::cout << "WrongAnimal default constructor called!" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type_arg): type(type_arg)
{
	std::cout << "WrongAnimal constructor called!" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called!" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
	*this = src;
}
WrongAnimal &WrongAnimal::operator=(WrongAnimal const & rhs)
{
	std::cout << "WrongAnimal operator assigment called!" << std::endl;
	if (this == &rhs)
		return *this;

	type = rhs.getType();
	return *this;
}
// METHODS 
const std::string &WrongAnimal::getType(void) const
{
	return type;
}

void  WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal makes a sound!" << std::endl;
}
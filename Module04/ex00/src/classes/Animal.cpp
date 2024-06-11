#include <Animal.hpp>

Animal::Animal(): type("undefined")
{
	std::cout << "Animal default constructor called!" << std::endl;
}
Animal::Animal(std::string type_arg): type(type_arg)
{
	std::cout << "Animal constructor called!" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}
Animal::Animal(Animal const & src)
{
	std::cout << "Animal copy constructor called!" << std::endl;
	*this = src;
}
Animal &Animal::operator=(Animal const & rhs)
{
	std::cout << "Animal operator assigment called!" << std::endl;
	if (this == &rhs)
		return *this;

	type = rhs.getType();
	return *this;
}
// METHODS 
const std::string &Animal::getType(void) const
{
	return type;
}

void  Animal::makeSound(void) const
{
	std::cout << "Animal makes a sound!" << std::endl;
}
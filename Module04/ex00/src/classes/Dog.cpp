#include <Dog.hpp>

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
}

Dog::Dog(const Dog & copy)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog operator assigment called!" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "bark" << std::endl;
}
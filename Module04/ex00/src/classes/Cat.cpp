#include <Cat.hpp>

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
}

Cat::Cat(const Cat & copy): Animal("Cat")
{
	std::cout << "Cat copy constructor called!" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat operator assigment called!" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "miau" << std::endl;
}
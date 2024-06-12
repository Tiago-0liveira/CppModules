#include <WrongCat.hpp>

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat & copy): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat copy constructor called!" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const & rhs)
{
	std::cout << "WrongCat operator assigment called!" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "wrong miau" << std::endl;
}
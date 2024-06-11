#include <Dog.hpp>

Dog::Dog(): Animal("Dog")
{
	brain = new Brain();
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called!" << std::endl;
}

Dog::Dog(const Dog & copy): Animal("Dog")
{
	std::cout << "Dog copy constructor called!" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog operator assigment called!" << std::endl;
	if (this == &rhs)
		return *this;
	brain = new Brain(*rhs.getBrain());
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "bark" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return brain;
}
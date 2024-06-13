#include <Dog.hpp>

Dog::Dog() : AAnimal("Dog")
{
	brain = new Brain();
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called!" << std::endl;
}

Dog::Dog(const Dog &copy): AAnimal("Dog")
{
	std::cout << "Dog copy constructor called!" << std::endl;
	brain = new Brain(*copy.getBrain());
	*this = copy;
}

Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog operator assigment called!" << std::endl;
	if (this == &rhs)
		return *this;
	*brain = *rhs.getBrain();
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
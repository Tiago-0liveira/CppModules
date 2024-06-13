#include <Cat.hpp>

Cat::Cat() : AAnimal("Cat")
{
	brain = new Brain();
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called!" << std::endl;
}

Cat::Cat(const Cat &copy): AAnimal("Cat")
{
	std::cout << "Cat copy constructor called!" << std::endl;
	brain = new Brain(*copy.getBrain());
	*this = copy;
}

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat operator assigment called!" << std::endl;
	if (this == &rhs)
		return *this;
	
	*brain = *rhs.getBrain();
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "miau" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return brain;
}
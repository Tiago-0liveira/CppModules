#ifndef DOG_HPP
#define DOG_HPP

#include <Animal.hpp>

class Dog: public Animal
{
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog & copy);
	Dog &operator=(Dog const & rhs);

	virtual void makeSound(void) const;
};

#endif // DOG_HPP
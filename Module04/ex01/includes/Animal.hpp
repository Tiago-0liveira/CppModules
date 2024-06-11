#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal();
	Animal(std::string type);
	virtual ~Animal();
	Animal(Animal const & src);
	Animal &operator=(Animal const & rhs);
	
	const std::string &getType(void) const;
	virtual void makeSound(void) const;
protected:
	std::string type;
};

#endif //ANIMAL_HPP

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
public:
	const std::string &getType(void) const;
	virtual void makeSound(void) const = 0;
protected:
	AAnimal(std::string const &type);
	virtual ~AAnimal();
	std::string type;
};

#endif // AANIMAL_HPP

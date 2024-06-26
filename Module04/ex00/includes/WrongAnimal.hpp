#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	virtual ~WrongAnimal();
	WrongAnimal(WrongAnimal const &src);
	WrongAnimal &operator=(WrongAnimal const &rhs);

	const std::string &getType(void) const;
	void makeSound(void) const;

protected:
	std::string type;
};

#endif // WRONGANIMAL_HPP

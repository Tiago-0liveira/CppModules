#ifndef AMATERIA_CPP
#define AMATERIA_CPP

#include <iostream>
#include <ICharacter.hpp>

class AMateria
{
protected:
	std::string type;

public:
	AMateria(std::string const &type);

	std::string const &getType() const;

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif // AMATERIA_CPP
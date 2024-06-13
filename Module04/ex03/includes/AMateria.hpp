#ifndef AMATERIA_CPP
#define AMATERIA_CPP

#include <iostream>
#include <ICharacter.hpp>

class ICharacter;

class AMateria
{
protected:
	std::string type;
	AMateria(std::string const &type);

public:
	AMateria(const AMateria &copy);
	AMateria &operator=(const AMateria &rhs);
	virtual ~AMateria();
	std::string const &getType() const;

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif // AMATERIA_CPP
#ifndef CURE_HPP
#define CURE_HPP

#include <AMateria.hpp>
#include <ICharacter.hpp>
#include <iostream>

class Cure: public AMateria
{
public:
	Cure();
	~Cure();
	Cure(const Cure & copy);
	Cure &operator=(Cure const & rhs);

	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};

#endif // CURE_HPP
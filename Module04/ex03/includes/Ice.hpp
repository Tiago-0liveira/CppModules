#ifndef ICE_HPP
#define ICE_HPP

#include <AMateria.hpp>
#include <ICharacter.hpp>
#include <iostream>

class Ice: public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice & copy);
	Ice &operator=(Ice const & rhs);

	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};

#endif // ICE_HPP
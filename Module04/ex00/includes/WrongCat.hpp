#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <WrongAnimal.hpp>

class WrongCat: public WrongAnimal
{
public:
	WrongCat();
	virtual ~WrongCat();
	WrongCat(const WrongCat & copy);
	WrongCat &operator=(WrongCat const & rhs);

	virtual void makeSound(void) const;
};

#endif // WRONGCAT_HPP
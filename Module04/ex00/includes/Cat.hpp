#ifndef CAT_HPP
#define CAT_HPP

#include <Animal.hpp>

class Cat: public Animal
{
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat & copy);
	Cat &operator=(Cat const & rhs);

	virtual void makeSound(void) const;
};

#endif // CAT_HPP
#ifndef CAT_HPP
#define CAT_HPP

#include <AAnimal.hpp>
#include <Brain.hpp>

class Cat : public AAnimal
{
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat &copy);
	Cat &operator=(Cat const &rhs);

	virtual void makeSound(void) const;
	Brain *getBrain(void) const;

private:
	Brain *brain;
};

#endif // CAT_HPP
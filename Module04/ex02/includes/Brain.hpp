#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define IDEAS_NUM 100

class Brain
{
public:
	Brain();
	~Brain();
	Brain(const Brain &copy);
	Brain &operator=(Brain const &rhs);

	std::string *getIdeas(void) const;
private:
	std::string *ideas;
};

#endif // BRAIN_HPP
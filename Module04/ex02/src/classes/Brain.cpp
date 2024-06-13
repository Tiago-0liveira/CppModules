#include <Brain.hpp>

Brain::Brain()
{
	ideas = new std::string[IDEAS_NUM];
	std::cout << "Brain default constructor called!" << std::endl;
}

Brain::~Brain()
{
	delete[] ideas;
	std::cout << "Brain destructor called!" << std::endl;
}

Brain::Brain(const Brain & copy)
{
	std::cout << "Brain copy constructor called!" << std::endl;
	ideas = new std::string[IDEAS_NUM];
	*this = copy;
}

Brain &Brain::operator=(Brain const & rhs)
{
	std::cout << "Brain operator assigment called!" << std::endl;
	if (this == &rhs)
		return *this;
	*ideas = *rhs.getIdeas();
	return *this;
}

std::string *Brain::getIdeas(void) const
{
	return ideas;
}

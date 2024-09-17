#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	typedef std::stack<T> stackT;
	typedef typename stackT::container_type::iterator iterator;
	
	MutantStack() : stackT() {}
	MutantStack(const MutantStack &other) : stackT(other) {}
	MutantStack &operator=(const MutantStack &other)
	{
		if (this == &other)
			return *this;
		stackT::operator=(other);
		return *this;
	}
	~MutantStack() {}
	
	iterator begin()
	{
		return stackT::c.begin();
	}
	iterator end()
	{
		return stackT::c.end();
	}
};


#endif //MUTANTSTACK_HPP

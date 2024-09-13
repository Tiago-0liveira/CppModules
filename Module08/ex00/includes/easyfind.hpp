#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <algorithm>

template<typename T>
int easyfind(T& container, int num)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		return -1;
	return *it;
}

#endif // FUNCS_HPP
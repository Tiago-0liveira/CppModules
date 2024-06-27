#ifndef FUNCS_HPP
#define FUNCS_HPP

template<typename T>
void	swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T&	min(T& a, T& b) {
	if (a > b)
		return b;
	return a;
}

template<typename T>
T&	max(T& a, T& b) {
	if (a > b)
		return a;
	return b;
}

#endif // FUNCS_HPP
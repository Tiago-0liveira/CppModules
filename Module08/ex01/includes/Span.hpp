#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <ctime>
#include <climits>
#include <cstdlib>


class Span
{
public:
    Span(unsigned int N);
    ~Span();
    Span(const Span& cpy);
    Span &operator=(const Span &rhs);

    void addNumber(int n);
	
	template <typename Iterator>
	void addRange(Iterator first, Iterator last) {
		if (elements + std::distance(first, last) > capacity)
			throw Span::MaximumCapacityReached();
		else
			elements += std::distance(first, last);
		arr.insert(arr.end(), first, last);
	}

    size_t shortestSpan();
    size_t longestSpan();
	
	void randomFill();
	
	class MaximumCapacityReached: public std::exception {
	public:
		virtual const char *what() const throw()
		{
			return "Span is already full!";
		}
	};
private:
	static int randomNumber();
	
	unsigned int elements;
	unsigned int capacity;
    std::vector<int> arr;
};

#endif // SPAN_HPP
#include <Span.hpp>

Span::Span(unsigned int N): elements(0), capacity(N) {}

Span::~Span() {}

Span::Span(const Span &rhs): elements(rhs.elements), capacity(rhs.capacity), arr(rhs.arr)
{
    *this = rhs;
}

Span &Span::operator=(const Span &rhs)
{
    if (this != &rhs)
    {
		elements = rhs.elements;
		capacity = rhs.capacity;
        arr = rhs.arr;
    }
    return *this;
}

void Span::addNumber(int n)
{
	if (arr.size() == capacity)
		throw Span::MaximumCapacityReached();
	
	arr.push_back(n);
	elements++;
}

size_t Span::shortestSpan()
{
	if (elements < 2)
		throw(std::out_of_range("Not enough elements for a span"));
	
	std::vector<int> sorted = arr;
	std::sort(sorted.begin(), sorted.end());
	size_t min = INT_MAX;
	for (std::vector<int>::iterator it = sorted.begin(); (it + 1) != sorted.end(); it++)
	{
		size_t absDiff = labs(static_cast<long int>(*it) - static_cast<long int>(*(it + 1)));
		if (absDiff == 0) return 0;
		if (absDiff < min)
			min = absDiff;
	}
	return min;
}

size_t Span::longestSpan()
{
	if (elements < 2)
		throw(std::out_of_range("Not enough elements for a span"));
	
	std::vector<int>::iterator min = std::min_element(arr.begin(), arr.end());
	std::vector<int>::iterator max = std::max_element(arr.begin(), arr.end());
	
	return labs(static_cast<long int>(*max) - static_cast<long int>(*min));
}

int Span::randomNumber()
{
	return rand();
}

void Span::randomFill()
{
	srand(std::time(NULL));
	for (;elements < capacity; elements++)
		arr.push_back(randomNumber());
	std::generate(arr.begin(), arr.end(), Span::randomNumber);
}

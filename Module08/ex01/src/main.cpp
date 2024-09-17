#include <iostream>
#include <Span.hpp>

int main()
{
	std::cout << "----sp 1----" << std::endl;
	
	Span sp = Span(5);
	
	sp.addNumber(INT_MAX);
	sp.addNumber(-1231231);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << "----Span error test----" << std::endl;
	
	try {
		sp.addNumber(11);
	}
	catch (Span::MaximumCapacityReached &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "----sp 2----" << std::endl;
	
	Span sp2(100000);
	sp2.randomFill();
	
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	
	std::cout << "----sp 3----" << std::endl;
	
	Span sp3(5);
	std::vector <int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	sp3.addRange(v.begin(), v.end());
	
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
	
	std::cout << "----sp 4----" << std::endl;
	
	Span sp4(sp);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << "----sp 5----" << std::endl;
	
	sp4 = sp3;
	
	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;
	
	return 0;
}

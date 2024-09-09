#include <iostream>
#include <ScalarConverter.hpp>

int main()
{
    std::cout << "-----------------" << std::endl;
    ScalarConverter::convert("0");
    std::cout << "-----------------" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << "-----------------" << std::endl;
    ScalarConverter::convert("42.0f");
    std::cout << "-----------------" << std::endl;
	return 0;
}

#include <utils.hpp>

std::string getValidStringInput()
{
	std::string input;
	do {
		std::getline(std::cin, input);
	} while (input.empty() && !std::cin.eof());
	return input;
}
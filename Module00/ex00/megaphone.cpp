#include <iostream>
#include <stdlib.h>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return EXIT_SUCCESS;
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			std::cout << (char)std::toupper((unsigned char)argv[i][j]); // Correct use of std::toupper
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
#include <iostream>
#include <RPN.hpp>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN <expression>" << std::endl;
		return 1;
	}

	try {
		RPN rpn(argv[1]);

		int res = rpn.evaluate();
		std::cout << "Result: " << res << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
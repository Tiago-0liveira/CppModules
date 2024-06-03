#include <iostream>

int main()
{
	std::string str ("HI THIS IS BRAIN");
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "address of variable 'str':    " << &str << std::endl;
	std::cout << "value of the 'str' variable:  " << str << std::endl;
	std::cout << "address of variable 'srtPTR':   " << strPTR << std::endl;
	
	std::cout << "value of the pointer 'strPTR' is pointing to: " << *strPTR << std::endl;
	std::cout << "address of variable 'srtREF':   " << &strREF << std::endl;
	std::cout << "value of the variable 'srtREF': " << strREF << std::endl;

}
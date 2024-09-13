#include <iostream>
#include <vector>

#include <easyfind.hpp>

int main()
{

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << easyfind(vec, 2) << std::endl;
    std::cout << easyfind(vec, 1) << std::endl;
    std::cout << easyfind(vec, -2) << std::endl;

	return 0;
}

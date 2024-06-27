#include <iostream>
#include <Array.hpp>

int main()
{
    Array<int> arr;
    Array<int> arr2(10);

    ++(*arr2.getRawArray()) = 10;
    std::cout << arr2[1] << std::endl;


	return 0;
}

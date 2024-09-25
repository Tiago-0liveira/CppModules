#include <iostream>
#include <PmergeMe.hpp>

#include <vector>
#include <list>

#include <set>
#include <sstream>

#include <climits>
#include <cerrno>
#include <ctime>


bool isValidInt(const std::string &str, int &result) {
    char *endptr;
    errno = 0;

    long val = std::strtol(str.c_str(), &endptr, 10);

    if (errno == ERANGE || val > INT_MAX || val < INT_MIN) {
        return false;  // Overflow or underflow occurred
    }

    if (*endptr != '\0') {
        return false;
    }

    result = static_cast<int>(val);
    return true;
}

bool insertToSetUniqueNumber(std::vector<int> &vec, std::set<int> &set, const std::string &str)
{
	int n = 0;
	if (!isValidInt(str, n))
	{
		std::cerr << "Error: Not a number or overflows int: " << n << std::endl;
		return false;
	}
	if (n < 0)
	{
		std::cerr << "Error: Negative number found: " << n << std::endl;
		return false;
	}
	if (!set.insert(n).second)
	{
		std::cerr << "Error: Duplicate number found: " << n << std::endl;
		return false;
	}
	vec.push_back(n);
	return true;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe \"<int sequence>\"" << std::endl;
		return 1;
	}
	std::set<int> number_table;
	std::vector<int> unique_numbers;
	if (argc == 2)
	{
		std::istringstream iss(argv[1]);
        std::string token;
        while (iss >> token)
        {
			if (!insertToSetUniqueNumber(unique_numbers, number_table, token))
				return 1;
        }
	} else {
		for (int i = 1; i < argc; ++i)
        {
			if (!insertToSetUniqueNumber(unique_numbers, number_table, argv[i]))
				return 1;
        }
	}

	std::vector<int> v;
	std::list<int> l;

	std::vector<int>::iterator vec_it = unique_numbers.begin();
	std::vector<int>::iterator vec_itend = unique_numbers.end();
	while (vec_it != vec_itend)
	{
		int n = *vec_it;
		v.push_back(n);
		l.push_back(n);
		vec_it++;
	}

	std::cout << "Before: ";
	showList(v);
	std::cout << std::endl;


	// Vector

	clock_t Vec_start = clock();
	mergeSortVector(v);
	double Vec_elapsed = double(clock() - Vec_start) / CLOCKS_PER_SEC;

	// List

	clock_t List_start = clock();
	mergeSortList(l);
	double List_elapsed = double(clock() - List_start) / CLOCKS_PER_SEC;	

	std::cout << "After:  ";
	showList(v);
	std::cout << std::endl;
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << std::fixed << Vec_elapsed << std::endl;
	std::cout << "Time to process a range of " << l.size() << " elements with std::list : " << std::fixed << List_elapsed << std::endl; 

	return 0;
}
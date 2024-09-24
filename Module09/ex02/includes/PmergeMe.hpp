#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

template<typename C>
void showList(const C &cont) {
	typename C::const_iterator C_it = cont.begin();
	typename C::const_iterator C_itend = cont.end();
	while (C_it != C_itend)
	{
		std::cout << *C_it << " ";
		C_it++;
	}
}

void mergeSortVector(std::vector<int> &vec);
void mergeVector(std::vector<int> &leftVec, std::vector<int> &rightVec, std::vector<int> &mainVec);

void mergeSortList(std::list<int> &vec);
void mergeList(std::list<int> &leftVec, std::list<int> &rightVec, std::list<int> &mainVec);

#endif //PMERGEME_HPP

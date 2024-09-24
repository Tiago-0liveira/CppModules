#include <PmergeMe.hpp>

void mergeSortVector(std::vector<int> &vec)
{
	typedef std::vector<int> C;

	size_t len = vec.size();
	if (len <= 1) return;

	size_t middle = len / 2;
	C leftVec(vec.begin(), vec.begin() + middle);
    C rightVec(vec.begin() + middle, vec.end());

	size_t i = 0;
	size_t j = 0;


	for (; i < len; i++)
	{
		if (i < middle)
		{
			leftVec[i] = vec[i];
		}
		else
		{
			rightVec[j] = vec[i];
			j++;
		}
	}
	mergeSortVector(leftVec);
	mergeSortVector(rightVec);
	mergeVector(leftVec, rightVec, vec);
}

void mergeVector(std::vector<int> &leftVec, std::vector<int> &rightVec, std::vector<int> &mainVec)
{
	size_t leftSize = mainVec.size() / 2;
	size_t rightSize = mainVec.size() - leftSize;
	size_t i, l, r;
	i = 0; l = 0; r = 0;

	while (l < leftSize && r < rightSize)
	{
		if (leftVec[l] < rightVec[r])
		{
			mainVec[i] = leftVec[l];
			l++;
		}
		else
		{
			mainVec[i] = rightVec[r];
			r++;
		}
		i++;
	}
	while (l < leftSize)
	{
		mainVec[i] = leftVec[l];
		i++;
		l++;
	}
	while (r < rightSize)
	{
		mainVec[i] = rightVec[r];
		i++;
		r++;
	}
}


void mergeSortList(std::list<int> &lst)
{
    if (lst.size() <= 1) return;

    std::list<int> leftList, rightList;
    std::list<int>::iterator it = lst.begin();
    size_t middle = lst.size() / 2;
    size_t index = 0;

    while (it != lst.end()) {
        if (index < middle) {
            leftList.push_back(*it);
        } else {
            rightList.push_back(*it);
        }
        ++it;
        ++index;
    }

    mergeSortList(leftList);
    mergeSortList(rightList);

    mergeList(leftList, rightList, lst);
}

void mergeList(std::list<int> &leftList, std::list<int> &rightList, std::list<int> &mainList)
{
    mainList.clear();

    std::list<int>::iterator itLeft = leftList.begin();
    std::list<int>::iterator itRight = rightList.begin();

    while (itLeft != leftList.end() && itRight != rightList.end()) {
        if (*itLeft <= *itRight) {
            mainList.push_back(*itLeft);
            ++itLeft;
        } else {
            mainList.push_back(*itRight);
            ++itRight;
        }
    }

    while (itLeft != leftList.end()) {
        mainList.push_back(*itLeft);
        ++itLeft;
    }

    while (itRight != rightList.end()) {
        mainList.push_back(*itRight);
        ++itRight;
    }

}
#include "PmergeMe.hpp"

std::vector<int> sortWithVector(const std::vector<int>& input)
{
	std::vector<int> vec = input;
	mergeInsertSort(vec, 0, vec.size() - 1);
	return vec;
}

void mergeInsertSort(std::vector<int>& vec, int left, int right) 
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeInsertSort(vec, left, mid);         
    mergeInsertSort(vec, mid + 1, right);   
    merge(vec, left, mid, right);      
}

void merge(std::vector<int>& vec, int left, int mid, int right) 
{
    std::vector<int> leftVec;
    std::vector<int> rightVec;

    for (int i = left; i <= mid; ++i)
        leftVec.push_back(vec[i]);
    for (int i = mid + 1; i <= right; ++i)
        rightVec.push_back(vec[i]);

    int i = 0, j = 0, k = left;

    while (i < (int)leftVec.size() && j < (int)rightVec.size()) 
    {
        if (leftVec[i] < rightVec[j])
            vec[k++] = leftVec[i++];
        else
            vec[k++] = rightVec[j++];
    }
    while (i < (int)leftVec.size())
        vec[k++] = leftVec[i++];
    while (j < (int)rightVec.size())
        vec[k++] = rightVec[j++];
}


std::deque<int> sortWithDeque(const std::vector<int>& input) 
{
	std::deque<int> deq(input.begin(), input.end());
	mergeInsertSort(deq, 0, deq.size() - 1);
	return deq;
}

void mergeInsertSort(std::deque<int>& deq, int left, int right) 
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	mergeInsertSort(deq, left, mid);
	mergeInsertSort(deq, mid + 1, right);
	merge(deq, left, mid, right);
}

void merge(std::deque<int>& deq, int left, int mid, int right)
{
    std::deque<int> leftDeq;
    std::deque<int> rightDeq;

    for (int i = left; i <= mid; ++i)
        leftDeq.push_back(deq[i]);
    for (int i = mid + 1; i <= right; ++i)
        rightDeq.push_back(deq[i]);

    int i = 0, j = 0, k = left;

    while (i < (int)leftDeq.size() && j < (int)rightDeq.size()) 
    {
        if (leftDeq[i] < rightDeq[j])
            deq[k++] = leftDeq[i++];
        else
            deq[k++] = rightDeq[j++];
    }
    while (i < (int)leftDeq.size())
        deq[k++] = leftDeq[i++];
    while (j < (int)rightDeq.size())
        deq[k++] = rightDeq[j++];
}

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::sortWithVector(const std::vector<int>& input) {
	std::vector<int> vec = input;
	mergeInsertSort(vec, 0, vec.size() - 1);
	return vec;
}

void PmergeMe::mergeInsertSort(std::vector<int>& vec, int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeInsertSort(vec, left, mid);         
    mergeInsertSort(vec, mid + 1, right);   
    merge(vec, left, mid, right);      
}

void PmergeMe::merge(std::vector<int>& vec, int left, int mid, int right) {
    std::vector<int> leftVec;
    std::vector<int> rightVec;

    for (int i = left; i <= mid; ++i)
        leftVec.push_back(vec[i]);
    for (int i = mid + 1; i <= right; ++i)
        rightVec.push_back(vec[i]);

    int i = 0, j = 0, k = left;

    while (i < (int)leftVec.size() && j < (int)rightVec.size()) {
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


std::deque<int> PmergeMe::sortWithDeque(const std::vector<int>& input) {
	std::deque<int> deq(input.begin(), input.end());
	mergeInsertSort(deq, 0, deq.size() - 1);
	return deq;
}

void PmergeMe::mergeInsertSort(std::deque<int>& deq, int left, int right) {
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	mergeInsertSort(deq, left, mid);
	mergeInsertSort(deq, mid + 1, right);
	merge(deq, left, mid, right);
}

void PmergeMe::merge(std::deque<int>& deq, int left, int mid, int right) {
	std::deque<int> temp;
	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right) {
		if (deq[i] <= deq[j])
			temp.push_back(deq[i++]);
		else
			temp.push_back(deq[j++]);
	}
	while (i <= mid)
		temp.push_back(deq[i++]);
	while (j <= right)
		temp.push_back(deq[j++]);

	for (int k = 0; k < static_cast<int>(temp.size()); ++k)
		deq[left + k] = temp[k];
}




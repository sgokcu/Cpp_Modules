#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
public:
	PmergeMe();
	~PmergeMe();

	std::vector<int> sortWithVector(const std::vector<int>& input);
	std::deque<int> sortWithDeque(const std::vector<int>& input);

private:
	void mergeInsertSort(std::vector<int>& vec, int left, int right);
	void merge(std::vector<int>& vec, int left, int mid, int right);

	void mergeInsertSort(std::deque<int>& deq, int left, int right);
	void merge(std::deque<int>& deq, int left, int mid, int right);
};

#endif

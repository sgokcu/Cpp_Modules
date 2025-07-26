#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <stdexcept>
#include <ctime>
#include <stdint.h>
#include <iomanip>
#include <chrono>
#include "PmergeMe.hpp"

bool isPositiveInteger(const std::string& str) {
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); ++i) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}
/*
bool isSorted(std::vector<int>& numbers)
{
    for (std::size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i - 1] >= numbers[i]) {
            return false;
        }
    }
    return true;
}
*/

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error: Not enough arguments." << std::endl;
		return 1;
	}

	std::vector<int> numbers;
	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		if (!isPositiveInteger(arg)) {
			std::cerr << "Error: Invalid input: " << arg << std::endl;
			return 1;
		}
		long long val = std::atoll(arg.c_str());
		if (val < 0 || val > INT32_MAX) {
			std::cerr << "Error: Number out of range: " << arg << std::endl;
			return 1;
		}
		numbers.push_back(static_cast<int>(val));
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	try {
		PmergeMe sorter;

		auto startVec = std::chrono::high_resolution_clock::now();
		std::vector<int> vecResult = sorter.sortWithVector(numbers);
		auto endVec = std::chrono::high_resolution_clock::now();

		auto startDeque = std::chrono::high_resolution_clock::now();
		std::deque<int> deqResult = sorter.sortWithDeque(numbers);
		auto endDeque = std::chrono::high_resolution_clock::now();

		std::cout << "After: ";
		for (size_t i = 0; i < vecResult.size(); ++i)
			std::cout << vecResult[i] << " ";
		std::cout << std::endl;
		
		
		std::chrono::duration<double, std::micro> timeVec = endVec - startVec;
        std::chrono::duration<double, std::micro> timeDeque = endDeque - startDeque;

		//if(isSorted(vecResult))
		//std::cout << "it is sorted perfectly <3" << std::endl; 


	    std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time with vector: " << timeVec.count() << " us" << std::endl;
        std::cout << "Time with deque : " << timeDeque.count() << " us" << std::endl;
	} 
	
	
	
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}

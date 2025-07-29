#include "PmergeMe.hpp"

bool isPositiveInteger(const std::string& str) 
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); ++i) 
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void isSorted(std::vector<int>& numbers)
{
    for (std::size_t i = 1; i < numbers.size(); ++i) 
    {
        if (numbers[i - 1] >= numbers[i])
			{
            std::cout << "it isn't sorted correctly." << std::endl;
				return ;
			}
    }
    std::cout << "it's sorted perfectly <3" << std::endl;
}

int main(int argc, char** argv) 
{
	if (argc < 2) 
	{
		std::cerr << "Error: Not enough arguments." << std::endl;
		return 1;
	}
	std::vector<int> numbers;
	for (int i = 1; i < argc; ++i) 
	{
		if (!isPositiveInteger(argv[i])) 
		{
			std::cerr << "Error: Invalid input: " << argv[i] << std::endl;
			return 1;
		}
		long long val = std::atoll(argv[i]);
		if (val < 0 || val > INT32_MAX) 
		{
			std::cerr << "Error: Number out of range: " << argv[i] << std::endl;
			return 1;
		}
		numbers.push_back(static_cast<int>(val));
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;
	try {
		std::clock_t startVec = std::clock();
		std::vector<int> vecResult = sortWithVector(numbers);
		std::clock_t endVec = std::clock();

		std::clock_t startDeque = std::clock();
		std::deque<int> deqResult = sortWithDeque(numbers);
		std::clock_t endDeque = std::clock();

		std::cout << "After: ";
		for (size_t i = 0; i < vecResult.size(); ++i)
			std::cout << vecResult[i] << " ";
		std::cout << std::endl;
		
		double timeVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;
		double timeDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;

		//isSorted(vecResult);

	    std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time with vector: " << timeVec << " us" << std::endl;
        std::cout << "Time with deque : " << timeDeque << " us" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}

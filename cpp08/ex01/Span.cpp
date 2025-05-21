#include "Span.hpp"

Span::Span() : capacity(10) {}

Span::Span(unsigned int n) : capacity(n) {}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span& Span::operator=(const Span& copy)
{
	if(this != &copy)
		*this = copy;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (numbers.size() >= capacity)
        throw std::runtime_error("Span is full!");
    numbers.push_back(num);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to compute span");

    std::vector<int> temp = numbers;
    std::sort(temp.begin(), temp.end());

    int minSpan = temp[1] - temp[0];
    for (size_t i = 1; i < temp.size() - 1; ++i) {
        int diff = temp[i + 1] - temp[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to compute span");

    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());

    return max - min;
}




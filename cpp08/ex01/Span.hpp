#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm> 
#include <stdexcept> 
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Span
{
private:
    unsigned int capacity;
    std::vector<int> numbers; 
public:
    Span();
    Span(unsigned int n);
    Span(const Span& copy);
    Span& operator=(const Span& copy);
    ~Span();
public:
    void addNumber(int num);
    int shortestSpan() const;
    int longestSpan() const;
public:
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) 
    {
       if (numbers.size() + std::distance(begin, end) > capacity)
           throw std::runtime_error("Adding these would exceed capacity");
       while (begin != end) {
           numbers.push_back(*begin);
           ++begin;
      }
    }
};



#endif
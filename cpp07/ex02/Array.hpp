#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>
#include <iostream>
#include <string>

template <typename T>
class Array {
private:
    T* _data;
    std::size_t _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    std::size_t size() const;
};

#include "Array.tpp"

#endif 
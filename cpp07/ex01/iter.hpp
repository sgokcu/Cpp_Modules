#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename F>
void iter(T* array, int length, F func) {
    for (int i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>
void printElement(T elmnt) {
    std::cout << elmnt << std::endl;
}

#endif 
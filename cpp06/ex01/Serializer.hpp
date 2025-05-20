#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>
#include <iostream>


class Serializer {
private:
    Serializer();
    Serializer(const Serializer& copy);
    Serializer& operator=(const Serializer& copy);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif

#pragma once

#include <iostream>

class Fixed
{
private:
    int fixed;
    const static int fractional = 8;
public:
    Fixed();
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& copy); 
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};


#pragma once

#include <iostream>
#include <cmath>

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
    Fixed(const int nbr);
    Fixed(const float nbr);

    int toInt( void ) const;
    float toFloat( void ) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

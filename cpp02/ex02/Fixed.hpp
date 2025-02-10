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

    float operator+(const Fixed fixed) const;
    float operator-(const Fixed fixed) const;
    float operator*(const Fixed fixed) const;
    float operator/(const Fixed fixed) const;
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    bool operator>(const Fixed &fixed) const;
    bool operator<(const Fixed &fixed) const;
    bool operator>=(const Fixed &fixed) const;
    bool operator<=(const Fixed &fixed) const;
    bool operator==(const Fixed &fixed) const;
    bool operator!=(const Fixed &fixed) const;
    // Static functions
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

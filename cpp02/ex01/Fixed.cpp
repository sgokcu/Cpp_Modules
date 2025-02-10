#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fixed = 0;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called"<< std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &copy)
        fixed = copy.getRawBits();

    return *this;
}

int Fixed::getRawBits() const
{
    return fixed;
}

void Fixed::setRawBits(int const raw)
{
    this->fixed = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
    std::cout << "Int constructor called" << std::endl;
    fixed = nbr << fractional;
}

Fixed::Fixed(const float nbr)
{
    std::cout << "Float constructor called" << std::endl;
    fixed = roundf(nbr * (1 << fractional));
}

int Fixed::toInt( void ) const
{
    return (fixed >> fractional);
}

float Fixed::toFloat( void ) const
{
    return((float)fixed / (1 << fractional));
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}

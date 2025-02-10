#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << type << ": default constructor called for WrongCat." << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy)
{
    std::cout << type << ": copy constructor called for WrongCat." << std::endl;
    brain = new Brain();
    *this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
    std::cout << type << ": copy assigment operator called for WrongCat." << std::endl;
    if(this != &copy)
        this->type = copy.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << type << ": destructor called for WrongCat." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "miyav." << std::endl;
}

std::string WrongCat::getType() const
{
    return type;
}
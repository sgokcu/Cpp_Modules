#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << type << ": default constructor called for Dog." << std::endl;
}
// zombi a(b)
Dog::Dog(const Dog& copy)
{
    std::cout << type << ": copy constructor called for Dog." << std::endl;
    *this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout << type << ": copy assigment operator called for Dog." << std::endl;
    if(this != &copy)
        this->type = copy.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << type << ": destructor called for Dog." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "hav hav." << std::endl;
}

std::string Dog::getType() const
{
    return type;
}
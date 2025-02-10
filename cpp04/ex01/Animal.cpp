#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "default constructor called for Animal." << std::endl;
}

Animal::Animal(const std::string& type)
{
    this->type = type;
    std::cout << type << ": default constructor called for Animal." << std::endl;
}

Animal::Animal(const Animal& copy)
{
    std::cout << type << ": copy constructor called for Animal." << std::endl;
    *this = copy;
}

Animal& Animal::operator=(const Animal& copy)
{
    std::cout << type << ": copy assigment operator called for Animal." << std::endl;
    if(this != &copy)
        this->type = copy.type;
    return *this;
}

Animal::~Animal()
{
    if(type == "")
        std::cout << "default destructor called for Animal." << std::endl;
    else
        std::cout << type << ": destructor called for Animal." << std::endl;
}
void Animal::makeSound() const
{
    std::cout << "Animal making sound." << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

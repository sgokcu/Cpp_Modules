#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << type << ": default constructor called for Cat." << std::endl;
}

Cat::Cat(const Cat& copy)
{
    std::cout << type << ": copy constructor called for Cat." << std::endl;
    *this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
    std::cout << type << ": copy assigment operator called for Cat." << std::endl;
    if(this != &copy)
        this->type = copy.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << type << ": destructor called for Cat." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miyav." << std::endl;
}
std::string Cat::getType() const
{
    return type;
}
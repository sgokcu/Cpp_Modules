#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "default constructor called for WrongAnimal." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type)
{
    this->type = type;
    std::cout << type << ": default constructor called for WrongAnimal." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    std::cout << type << ": copy constructor called for WrongAnimal." << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
    std::cout << type << ": copy assigment operator called for WrongAnimal." << std::endl;
    if(this != &copy)
        this->type = copy.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    if(type == "")
        std::cout << "default destructor called for WrongAnimal." << std::endl;
    else
        std::cout << type << ": destructor called for WrongAnimal." << std::endl;
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal making sound." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}
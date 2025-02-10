#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
    this->name = "";
}

Zombie::Zombie(const std::string& name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << name << " has ben destroyed :)" << std::endl;
}

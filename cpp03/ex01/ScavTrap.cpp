#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->name = "Default";
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << name << ": default constructor called for ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
{
    this->name = name;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << name << ": default constructor called for ScavTrap." << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap& copy)
{
    std::cout << name << ": copy constructor called for ScavTrap." << std::endl;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    std::cout << name << ": copy assigment operator called for ScavTrap." << std::endl;
    if(this != &copy)
    {
        this->name = name;
        this->hit_point = hit_point;
        this->energy_points = energy_points;
        this->attack_damage = attack_damage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << name << ": destructor called for ScavTrap." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(hit_point == 0)
        std::cout << "no points for ScavTrap to attack." << std::endl;
    else if(energy_points == 0)
        std::cout << "no energy for ScavTrap to attack." << std::endl;
    else
    {
        std::cout << "ScavTrap " << name << " attacks " << target 
        << ", causing " << attack_damage << " points of damage." << std::endl;
        energy_points--;
    }
        
}

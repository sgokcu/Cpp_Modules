#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->name = "Default";
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << name << ": default constructor called for FragTrap." << std::endl;
}

FragTrap::FragTrap(const std::string& name)
{
    this->name = name;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << name << ": default constructor called for FragTrap." << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
{
    std::cout << name << ": copy constructor called for FragTrap." << std::endl;
    *this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    std::cout << name << ": copy assigment operator called for FragTrap." << std::endl;
    if(this != &copy)
    {
        this->name = name;
        this->hit_point = hit_point;
        this->energy_points = energy_points;
        this->attack_damage = attack_damage;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "it's gonna be legend -wait for it- dary. High fivee :)" << std::endl;
}


FragTrap::~FragTrap()
{
    std::cout << name << ": destructor called for FragTrap." << std::endl;
}


void FragTrap::attack(const std::string& target)
{
    if(hit_point == 0)
        std::cout << "no points for FragTrap to attack." << std::endl;
    else if(energy_points == 0)
        std::cout << "no energy for FragTrap to attack." << std::endl;
    else
    {
        std::cout << "FragTrap " << name << " attacks " << target 
        << ", causing " << attack_damage << " points of damage." << std::endl;
        energy_points--;
    }
        
}

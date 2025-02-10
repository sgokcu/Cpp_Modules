#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
{
    this->name = name;
    this->hit_point = 100;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << name << ": default constructor called for ClapTrap." << std::endl;
}

ClapTrap::ClapTrap()
{
    this->name = "Default";
    this->hit_point = 100;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << name <<  ": default constructor called for ClapTrap." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << name << ": copy constructor called for ClapTrap." << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
    std::cout << name << ": opy assigment operator called for ClapTrap." << std::endl;
    if(this != &copy)
    {
        this->name = copy.name;
        this->hit_point = copy.hit_point;
        this->energy_points = copy.energy_points;
        this->attack_damage = copy.attack_damage;
    }
    return *this;
}


ClapTrap::~ClapTrap()
{
    std::cout << name << ": destructor called for ClapTrap." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(hit_point == 0)
        std::cout << "no points for attacking." << std::endl;
    else if(energy_points == 0)
        std::cout << "no energy for attacking." << std::endl;
    else
    {
        std::cout << "ClapTrap " << name << " attacks " << target 
        << ", causing " << attack_damage << " points of damage." << std::endl;
        energy_points--;
    }
        
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if(hit_point >= amount)
    {
        std::cout << "ClapTrap " << name << " took " << amount
        << " damage." << std::endl;
        hit_point -= amount;
    }
    else
    {
        std::cout << "ClapTrap " << name << " took " << amount
        << " damage." << std::endl;
        hit_point = 0;
    }

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(hit_point == 0)
        std::cout << "ClapTrap " << name << " can't repaired itself because it doesn't have any hit points." << std::endl;
    else if(energy_points == 0)
        std::cout << "ClapTrap " << name << " can't repaired itself because it doesn't have any energy points." << std::endl;
    else
    {
        std::cout << "ClapTrap " << name << " repaired " << amount 
        << " hit points." << std::endl;
        energy_points--;
        hit_point += amount;
    }

}

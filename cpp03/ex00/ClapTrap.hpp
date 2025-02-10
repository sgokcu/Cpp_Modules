#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string name;
    unsigned int hit_point;
    unsigned int energy_points;
    unsigned int attack_damage;
public:
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ClapTrap(const std::string& name);
    ClapTrap& operator=(const ClapTrap& copy);
    ClapTrap();
    ClapTrap(const ClapTrap& copy);
    ~ClapTrap();
};


#endif


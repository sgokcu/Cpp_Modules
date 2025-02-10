#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"


class HumanB
{
public:
    Weapon* weapon;
    std::string name;
    
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack();
};


#endif

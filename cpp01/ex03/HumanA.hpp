#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"


class HumanA
{
public:
    Weapon& weapon;
    std::string name;

    HumanA(std::string name, Weapon& weapon);
    void attack();
};

#endif

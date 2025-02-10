#include "Weapon.hpp"

void Weapon::setType(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType()
{
    return type;
}

Weapon::Weapon()
{
    this->type = "";
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

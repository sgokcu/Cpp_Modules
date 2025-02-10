#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    void announce(void);
    Zombie();
    Zombie(const std::string& name);
    ~Zombie();
};
    void randomChamp(const std::string& name);
    Zombie* newZombie(const std::string& name);

#endif

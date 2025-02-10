#include "Zombie.hpp"

int main()
{
    Zombie zombie = Zombie("Jacob");
    Zombie* zom = newZombie("Edward");
    zom->announce();
    randomChamp("Bella");
    delete zom;
}
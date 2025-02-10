#include "Zombie.hpp"

int main()
{
    int n = 6;
    Zombie* zom = zombieHorde(n, "Jacob");
    for(int i = 0; i < n; i++)
        zom->announce();
    delete[] zom;
}

#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* m = new Animal();
    const WrongAnimal* e = new WrongAnimal();
    const WrongAnimal* t = new WrongCat();
    const Animal* i = new Dog();
    const Animal* j = new Cat();
    std::cout << "*************************************************" << std::endl;
    std::cout << m->getType() << std::endl;
    std::cout << e->getType() << std::endl;
    std::cout << t->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << "*************************************************" << std::endl;
    m->makeSound();
    e->makeSound();
    t->makeSound();
    i->makeSound();
    j->makeSound();
    std::cout << "*************************************************" << std::endl;
    delete m;
    delete e;
    delete t;
    delete i;
    delete j;
}

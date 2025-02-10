#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
    }
    std::cout << "*************************************************" << std::endl;
    {
        Animal* animals[12];
        for(int i = 0; i < 6; i++)
            animals[i] = new Dog();
        for(int i = 6; i <= 11; i++)
            animals[i] = new Cat();
        for(int i = 0; i < 12; i++)
            delete animals[i];
    }
    std::cout << "*************************************************" << std::endl;
    {
        Dog* j = new Dog("hello");
        Dog* i = new Dog();

        *j = *i;
        j->printIdeas();
        i->printIdeas();
        delete i;
        delete j;
    }

}

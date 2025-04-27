#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : target(target), Sgrade(25), Egrade(5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : target(copy.target), Sgrade(copy.Sgrade), Egrade(copy.Egrade) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if(this != &copy)
		*this = copy;
	return *this;
}

void PresidentialPardonForm::action()
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// int main()
// {
//     std::srand(std::time(0)); // sadece 1 kez çağırıyoruz, yoksa her çalıştırmada aynı sayı çıkar.
    

//     int min = 1;
//     int max = 100;

//     int randomNumber = min + (std::rand() % (max - min + 1)); // min ile max arası sayı üretir

//     std::cout << "Random number: " << randomNumber << std::endl;

//     return 0;
// }
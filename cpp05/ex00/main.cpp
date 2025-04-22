#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat bro = Bureaucrat("Tanya0", 65);
	Bureaucrat bro1 = Bureaucrat("Tanya1", 1);
	Bureaucrat bro2 = Bureaucrat("Tanya2", 150);
	Bureaucrat bro3 = Bureaucrat("Tanya3", 0);
	Bureaucrat bro4 = Bureaucrat("Tanya4", 151);
	std::cout << bro << std::endl;
	bro.increment();
	bro.increment();
	bro.increment();
	std::cout << bro << std::endl;
	bro.decrement();
	std::cout << bro << std::endl;
	bro1.increment();
	bro2.decrement();
	//std::cout << bro3 << std::endl;
	//std::cout << bro4 << std::endl;
	
	
}
#include "Intern.hpp"

Intern::Intern() {}


Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern& Intern::operator=(const Intern& copy)
{
	if(this != &copy)
		*this = copy;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string name, std::string target)
{
	int j = 0; 
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* (Intern::*funcs[3])(const std::string&) = {&Intern::pp, &Intern::rr, &Intern::sc};
	
	for (size_t i = 0; i < 3; i++)
	{
		if(name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			j = 1;
			return (this->*funcs[i])(target);
		}
	}
	if (j == 0)
		std::cout << "Provided form name does not exist" << std::endl;
	return NULL;
	
}

AForm* Intern::sc(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}
AForm* Intern::rr(const std::string& target)
{
	return new RobotomyRequestForm(target);
}
AForm* Intern::pp(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

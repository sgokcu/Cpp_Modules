
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& copy);
	~Intern();
public:
	AForm* makeForm(std::string name, std::string target);
	AForm* sc(const std::string& target);
	AForm* rr(const std::string& target);
	AForm* pp(const std::string& target);
};



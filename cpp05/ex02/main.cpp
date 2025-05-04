#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat cat = Bureaucrat("Cat", 1);
	Bureaucrat dog = Bureaucrat("Dog", 150);
	ShrubberyCreationForm berry = ShrubberyCreationForm("Home");
	PresidentialPardonForm pardon = PresidentialPardonForm("Mr.President");
	RobotomyRequestForm robot = RobotomyRequestForm("Wall-E");
	
	dog.signForm(pardon);
	dog.executeForm(pardon);
	std::cout << "**************************************" << std::endl;
	dog.signForm(robot);
	dog.executeForm(robot);
	std::cout << "**************************************" << std::endl;
	dog.signForm(berry);
	dog.executeForm(berry);
	std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
	cat.signForm(berry);
	cat.executeForm(berry);
	std::cout << "**************************************" << std::endl;
	cat.signForm(pardon);
	cat.executeForm(pardon);
	std::cout << "**************************************" << std::endl;
	cat.signForm(robot);
	cat.executeForm(robot);
	std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
	dog.signForm(pardon);
	dog.executeForm(pardon);
}


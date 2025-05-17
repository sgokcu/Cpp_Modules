#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


int main()
{
	Bureaucrat cat = Bureaucrat("Cat", 1);
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Wall-E");
		std::cout << *rrf << std::endl;
		cat.signForm(*rrf);
		cat.executeForm(*rrf);
		delete rrf;
	}
	std::cout << "**************************************" << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Mr.President");
		std::cout << *rrf << std::endl;
		cat.signForm(*rrf);
		cat.executeForm(*rrf);
		delete rrf;
	}	
	std::cout << "**************************************" << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
		std::cout << *rrf << std::endl;
		cat.signForm(*rrf);
		cat.executeForm(*rrf);
		delete rrf;
	}
	std::cout << "**************************************" << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("wrongform example", "Wall-E");
		delete rrf;
	}
	
}


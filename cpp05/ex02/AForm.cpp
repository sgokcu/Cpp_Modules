#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm::GradeTooHighException.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm::GradeTooLowException.";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm::FormNotSignedException.";
}


int AForm::checkk(int grade)
{
	try
	{
		if(grade < 1)
			throw GradeTooHighException();
		else if(grade > 150)
			throw GradeTooLowException();
		else
			return grade;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 0;
	}
}

int AForm::beSigned(Bureaucrat& Bureaucrat)
{
	if(Bureaucrat.getGrade() <= getSgrade())
	{
		isSigned = 1;
		return 1;
	}
	return 0;
}

AForm::AForm() : name("Default"), isSigned(0), Sgrade(48), Egrade(56) {}

AForm::AForm(const std::string& name, int Sgrade, int Egrade) : name(name), Sgrade(checkk(Sgrade)), Egrade(checkk(Egrade)) 
{
	this->isSigned = 0;
}

AForm::AForm(const AForm& copy) : name(copy.name), Sgrade(copy.Sgrade), Egrade(copy.Egrade) 
{
	*this = copy;
}

AForm& AForm::operator=(const AForm& copy)
{
	if(this != &copy)
		*this = copy;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return name;
}

int AForm::getSgrade() const
{
	return Sgrade;
}

int AForm::getEgrade() const
{
	return Egrade;
}

int AForm::getIsSigned() const
{
	return isSigned;
}

std::ostream &operator<<(std::ostream &o, AForm &object)
{
    o << "Forms name: " << object.getName() << ", Forms sign grade: " << object.getSgrade() << ", Forms execute grade: " << object.getEgrade();
    if(object.getIsSigned() == 0)
        std::cout << ", Forms status: not signed";
    else
        std::cout << ", Forms status: signed";
    return (o);
}

void AForm::action() const
{
	std::cout << "actioning" << std::endl;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if(this->getIsSigned() == 0)
		throw FormNotSignedException();
	else if(executor.getGrade() > getEgrade())
		throw GradeTooLowException();
	else
		this->action();
}

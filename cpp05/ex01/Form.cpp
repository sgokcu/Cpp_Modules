#include "Form.hpp"
#include "Bureaucrat.hpp"

class GradeTooHighException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Form::GradeTooHighException.";
	}
};

class GradeTooLowException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Form::GradeTooLowException.";
	}
};

int Form::checkk(int grade)
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

int Form::beSigned(Bureaucrat& Bureaucrat)
{
	if(Bureaucrat.getGrade() <= getSgrade())
	{
		isSigned = 1;
		return 1;
	}
	return 0;
}

Form::Form() : name("Default"), isSigned(0), Sgrade(48), Egrade(56) {}

Form::Form(const std::string& name, int Sgrade, int Egrade) : name(name), Sgrade(checkk(Sgrade)), Egrade(checkk(Egrade)) 
{
	this->isSigned = 0;
}

Form::Form(const Form& copy) : name(copy.name), Sgrade(copy.Sgrade), Egrade(copy.Egrade) 
{
	*this = copy;
}

Form& Form::operator=(const Form& copy)
{
	if(this != &copy)
		*this = copy;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
	return name;
}

int Form::getSgrade()
{
	return Sgrade;
}

int Form::getEgrade()
{
	return Egrade;
}

int Form::getIsSigned()
{
	return isSigned;
}

std::ostream &operator<<(std::ostream &o, Form &object)
{
    o << "Forms name: " << object.getName() << ", Forms sign grade: " << object.getSgrade() << ", Forms execute grade: " << object.getEgrade();
    if(object.getIsSigned() == 0)
        std::cout << ", Forms status: not signed";
    else
        std::cout << ", Forms status: signed";
    return (o);
}

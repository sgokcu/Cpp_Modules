#include "Bureaucrat.hpp"

class GradeTooHighException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Bureaucrat::GradeTooHighException.";
	}
};

class GradeTooLowException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Bureaucrat::GradeTooLowException.";
	}
};

Bureaucrat::Bureaucrat() : name("Default"), grade(75) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	try
	{
		if(grade < 1)
			throw GradeTooHighException();
		else if(grade > 150)
			throw GradeTooLowException();
		else
			this->grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if(this != &copy)
		*this = copy;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade()
{
	return grade;
}

void Bureaucrat::increment()
{
	int a = grade - 1;
	try
	{
		if(a < 1)
			throw GradeTooHighException();
		else
			grade--;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void Bureaucrat::decrement()
{
	int a = grade + 1;
	try
	{
		if(a > 150)
			throw GradeTooLowException();
		else
			grade++;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &object)
{
    o << object.getName() << ", bureaucrat grade " << object.getGrade();
    return (o);
}

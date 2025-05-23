#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat::GradeTooHighException.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat::GradeTooLowException.";
}

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

int Bureaucrat::getGrade() const
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

void Bureaucrat::signForm(AForm& form)
{
	if(form.beSigned(*this) == 1)
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because bureaucrat's grade is not high enough" << std::endl;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &object)
{
    o << object.getName() << ", bureaucrat grade " << object.getGrade();
    return (o);
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		if(!form.getIsSigned())
			throw AForm::FormNotSignedException();
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
        std::cout << name << " couldn't executed " << form.getName() << " because " << e.what() << std::endl;
	}
}
	

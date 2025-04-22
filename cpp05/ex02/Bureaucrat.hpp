#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
#include <exception>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	std::string getName() const;
	int getGrade();
	void increment();
	void decrement();
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	~Bureaucrat();
	void signForm(AForm& form);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &grade);

#endif
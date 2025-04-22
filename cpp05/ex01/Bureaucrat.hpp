#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"
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
	int GradeHelper(int grade);
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	~Bureaucrat();
	void signForm(Form& form);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &grade);

#endif
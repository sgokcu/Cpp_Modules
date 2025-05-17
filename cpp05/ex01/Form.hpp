#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int Sgrade;
	const int Egrade;
public:
	std::string getName() const;
	int getSgrade();
	int getEgrade();
	int getIsSigned();
	int beSigned(Bureaucrat& Bureaucrat);
	static int checkk(const int grade);
public:
	Form(const std::string& name, int Sgrade, int Egrade);
	Form();
	Form(const Form& copy);
	Form& operator=(const Form& copy);
	~Form();
};

std::ostream &operator<<(std::ostream &o, Form &grade);

#endif
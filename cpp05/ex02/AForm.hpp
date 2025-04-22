#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
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
	AForm();
	AForm(const std::string& name, int Sgrade, int Egrade);
	AForm(const AForm& copy);
	AForm& operator=(const AForm& copy);
	~AForm();
	int beSigned(Bureaucrat& Bureaucrat);
	static int checkk(const int grade);
};

std::ostream &operator<<(std::ostream &o, AForm &grade);

#endif
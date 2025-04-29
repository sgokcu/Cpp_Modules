#ifndef ROBOTOMY_REQUEST_FORM
#define ROBOTOMY_REQUEST_FORM

#include <iostream>
#include <cstdlib>
#include <ctime> 
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string target;
	const int Sgrade;
	const int Egrade;
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
	RobotomyRequestForm(const std::string target);
public:
	void action() const;
public:

};

#endif

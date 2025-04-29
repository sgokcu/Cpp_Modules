#ifndef PRESIDENTIAL_PARDON_FORM
#define PRESIDENTIAL_PARDON_FORM

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string target;
	const int Sgrade;
	const int Egrade;
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
	PresidentialPardonForm(const std::string target);
public:
	void action() const;
public:

};

#endif

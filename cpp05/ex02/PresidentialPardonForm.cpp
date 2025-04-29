#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default"), Sgrade(25), Egrade(5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target), Sgrade(25), Egrade(5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : target(copy.target), Sgrade(copy.Sgrade), Egrade(copy.Egrade) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if(this != &copy)
		*this = copy;
	return *this;
}

void PresidentialPardonForm::action() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

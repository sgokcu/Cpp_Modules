#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("PresidentialPardonForm", 72, 45), target("Default"), Sgrade(72), Egrade(45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("PresidentialPardonForm", 72, 45), target(target), Sgrade(72), Egrade(45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : target(copy.target), Sgrade(copy.Sgrade), Egrade(copy.Egrade) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if(this != &copy)
		*this = copy;
	return *this;
}

void RobotomyRequestForm::action() const
{
    int i;
    std::srand(std::time(0));
    std::cout << "Diiiiiiiiiirrrrrrrr!!!!!!!!" << std::endl;

    i = std::rand() % 2;
    if(i == 0)
        std::cout << "Robotomy has been faild." << std::endl;
    else
        std::cout << target << " has been robotomized successfully which it happens 50% of the time." << std::endl;
}

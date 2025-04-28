#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : target(target), Sgrade(72), Egrade(45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : target(copy.target), Sgrade(copy.Sgrade), Egrade(copy.Egrade) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if(this != &copy)
		*this = copy;
	return *this;
}

void RobotomyRequestForm::action()
{
    int i;
    std::srand(std::time(0));
    std::cout << "Dııııııııırrrrrrr!!!!!!!!" << std::endl;

    i = std::rand() % 2;
    std::cout << i << std::endl;//denemek için koydun silmeyi unutma!!!!!!!!!!!!!!!
    if(i = 0)
        std::cout << "Robotomy has been faild." << std::endl;
    else
        std::cout << target << " has been robotomized successfully which it happens 50% of the time." << std::endl;
}

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default"), Sgrade(145), Egrade(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target), Sgrade(145), Egrade(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : target(copy.target), Sgrade(copy.Sgrade), Egrade(copy.Egrade) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if(this != &copy)
		*this = copy;
	return *this;
}

void ShrubberyCreationForm::action() const
{
	std::ofstream stream((target + "_shrubbery").c_str());

    if (!stream)
        std::cout << "Error: couldn't open the file " << target + "_shrubbery" << std::endl;

    stream << "            &&& &&  & &&" << std::endl;
    stream << "        && &\\/&\\|& ()|/ @, &&" << std::endl;
    stream << "        &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    stream << "     &() &\\/&|()|/&\\/ '%' & ()" << std::endl;
    stream << "    &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    stream << "  &&   && & &| &| /& & % ()& /&&" << std::endl;
    stream << "   ()&_---()&\\&\\|&&-&&--%---()~"<< std::endl;
    stream << "       &&     \\|||" << std::endl;
    stream << "               |||" << std::endl;
    stream << "               |||" << std::endl;
    stream << "               |||" << std::endl;
    stream << "         , -=-~  .-^- _" << std::endl;

	stream.close();
}


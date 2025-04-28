#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : target(target), Sgrade(145), Egrade(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : target(copy.target), Sgrade(copy.Sgrade), Egrade(copy.Egrade) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if(this != &copy)
		*this = copy;
	return *this;
}

void ShrubberyCreationForm::action()
{
	std::ofstream	stream;

	stream.open(std::string(target + "_shrubbery")); //yapamadım gibi geldi çalıştırmayı dene!!!!!!!!!!!!!
    if (!stream.is_open())
        return ;
    stream << "            &&& &&  & &&" << std::endl;
    stream << "        && &\/&\|& ()|/ @, &&" << std::endl;
    stream << "        &\/(/&/&||/& /_/)_&/_&" << std::endl;
    stream << "     &() &\/&|()|/&\/ '%' & ()" << std::endl;
    stream << "    &_\_&&_\ |& |&&/&__%_/_& &&" << std::endl;
    stream << "  &&   && & &| &| /& & % ()& /&&" << std::endl;
    stream << "   ()&_---()&\&\|&&-&&--%---()~"<< std::endl;
    stream << "       &&     \|||" << std::endl;
    stream << "               |||" << std::endl;
    stream << "               |||" << std::endl;
    stream << "               |||" << std::endl;
    stream << "         , -=-~  .-^- _" << std::endl;

}

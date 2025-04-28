#ifndef SHRUBBERY_CREATION_FORM
#define SHRUBBERY_CREATION_FORM

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string target;
	const int Sgrade;
	const int Egrade;
public:
	ShrubberyCreationForm(const std::string target);//bu da değiştirilmeli!!!!! ve pdfte 11.sayfada kaldın.
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
public:
	void action();
public:

};

#endif

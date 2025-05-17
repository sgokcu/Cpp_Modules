#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Form foorm = Form("form", 65, 34);
	Form foorm1 = Form("form1", 42, 58);
	Form foorm2 = Form("form2", 55, 90);
	Bureaucrat bro = Bureaucrat("Tanya0", 1);
	Bureaucrat bro1 = Bureaucrat("Tanya1", 80);
	
	std::cout << foorm << std::endl;
	bro.signForm(foorm);
	std::cout << foorm << std::endl;
	std::cout << "*******************************************************************************************"<< std::endl;
	std::cout << foorm1 << std::endl;
	foorm1.beSigned(bro);
	std::cout << foorm1 << std::endl;
	std::cout << "*******************************************************************************************"<< std::endl;
	std::cout << foorm2 << std::endl;
	bro1.signForm(foorm2);
	std::cout << foorm2 << std::endl;
	std::cout << "*******************************************************************************************"<< std::endl;
	Form foorm3 = Form("form3", 0, 34);
	Form foorm4 = Form("form4", 68, 152);
	Form foorm5 = Form("form5", 0, 155);	

}
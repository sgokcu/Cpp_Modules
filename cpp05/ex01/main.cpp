#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Form foorm = Form("form0", 65, 34);
	Form foorm1 = Form("form1", 42, 58);
	Bureaucrat bro = Bureaucrat("Tanya", 1);
	
	std::cout << foorm << std::endl;
	bro.signForm(foorm);
	std::cout << foorm << std::endl;
	std::cout << "*******************************************************************************************"<< std::endl;
	std::cout << foorm1 << std::endl;
	foorm1.beSigned(bro);
	std::cout << foorm1 << std::endl;
	// hata durumunu yaz grade kısmında ve try catchde returnde bi sıkıntı vardı sankii!!!!!!!
	// default constructorım yok onu da eklemen lazım!!!

	
}
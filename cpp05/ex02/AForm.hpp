#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int Sgrade;
	const int Egrade;
public:
	std::string getName() const;
	virtual int getSgrade() const;
	virtual int getEgrade() const;
	int getIsSigned() const;
	int beSigned(Bureaucrat& Bureaucrat);
	static int checkk(const int grade);
	virtual void execute(Bureaucrat const & executor) const;
	virtual void action() const = 0;
public:
	AForm(const AForm& copy);
	AForm();
	AForm& operator=(const AForm& copy);
	virtual ~AForm();
	AForm(const std::string& name, int Sgrade, int Egrade);
public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class FormNotSignedException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, AForm &grade);

#endif
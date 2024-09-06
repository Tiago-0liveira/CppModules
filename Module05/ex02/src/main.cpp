#include <iostream>
#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

int main()
{	
	Bureaucrat b1("Ricardo", 1);
	Bureaucrat b2("Tiago", 145);
	Bureaucrat b3("Vasco", 150);
	
	std::cout << b1 << std::endl;

	PresidentialPardonForm ppf("target");
	RobotomyRequestForm rrf("target");
	ShrubberyCreationForm scf("target");

	std::cout << scf << std::endl;

	b1.signForm(ppf);
	b1.signForm(rrf);

	b1.executeForm(ppf);

	b2.signForm(scf);
	b1.signForm(scf);
	ShrubberyCreationForm asd(scf);
	b1.executeForm(scf);

	b1.signForm(asd);

	b1.executeForm(rrf);

	return 0;
}

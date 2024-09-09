#include <iostream>
#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

int main()
{	
	Bureaucrat b1("Ricardo", 1);
	Bureaucrat b2("Tiago", 150);
	Bureaucrat b3("Vasco", 75);
	
	std::cout << b1 << std::endl;

	PresidentialPardonForm ppf("target");
	RobotomyRequestForm rrf("target");
	ShrubberyCreationForm scf("target");

	std::cout << ppf << std::endl;

	b1.signForm(ppf);
	b1.signForm(rrf);

	b1.executeForm(ppf);

	b1.signForm(scf);

	b1.executeForm(scf);

	b1.signForm(rrf);

	b1.executeForm(rrf);


	return 0;
}

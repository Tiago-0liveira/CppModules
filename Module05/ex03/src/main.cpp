#include <iostream>

#include <AForm.hpp>
#include <Intern.hpp>

int main()
{	
	Intern intern;
	AForm *form;

	form = intern.makeForm("robasdasdotomy request", "Bender");
	if (!form)
		return 0;
	form->beSigned(Bureaucrat("Hermes", 1));
	form->execute(Bureaucrat("Hermes", 1));

	delete form;

	return 0;
}

#include <iostream>
#include <Form.hpp>
#include <Bureaucrat.hpp>

int main()
{	
	Form form("Petiçao", 1, 1);

	Bureaucrat bureaucrat("Ricardo", 1);

	try {
		Form form2("Invalid Form", 150, 0);
	} catch (Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << form << std::endl;

	bureaucrat.signForm(form);
	bureaucrat.signForm(form);

	std::cout << form << std::endl;

	return 0;
}

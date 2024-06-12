#include <iostream>
#include <Form.hpp>
#include <Bureaucrat.hpp>

int main()
{	
	Form form("Petiçao", 1, 1);

	Bureaucrat bureaucrat("Ricardo", 1);

	std::cout << form << std::endl;

	bureaucrat.signForm(form);

	std::cout << form << std::endl;

	return 0;
}

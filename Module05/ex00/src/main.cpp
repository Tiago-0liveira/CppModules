#include <iostream>
#include <Bureaucrat.hpp>

int main()
{	
	try {
        Bureaucrat b1("John", 0);  // This should throw GradeTooHighException
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Doe", 200);  // This should throw GradeTooLowException
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Jane", 50);  // This should not throw any exception
        std::cout << b3 << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	Bureaucrat b4("Alice", 3);
	b4.incrementGrade();
	
	std::cout << b4 << std::endl;

	return 0;
}

#include <iostream>

#include <AForm.hpp>
#include <Intern.hpp>

int main()
{	
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
		delete rrf;
	rrf = someRandomIntern.makeForm("asd", "asd");

	return 0;
}

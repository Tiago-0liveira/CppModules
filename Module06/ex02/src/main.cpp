#include <iostream>
#include <ctime>
#include <cstdlib>

#include <Base.hpp>

#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

static Base *generate(void)
{
	srand(std::time(NULL));
	int i = rand() % 3;
	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else
		return new C();
}

static void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Identify by pointer: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Identify by pointer: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Identify by pointer: C" << std::endl;
	else
		std::cout << "Identify by pointer: Unknown" << std::endl;
}

static void identify(Base &p)
{
	try {
		dynamic_cast<A &>(p);
		std::cout << "Identify by ref: A" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		dynamic_cast<B &>(p);
		std::cout << "Identify by ref: B" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		dynamic_cast<C &>(p);
		std::cout << "Identify by ref: C" << std::endl;
		return ;
	} catch (std::exception &e) {}
}

int main()
{
	Base *base = generate();
	Base *base2 = generate();
	
	/* Identify by pointer */
	identify(base);
	identify(*base);
	
	/* Identify by ref */
	identify(base2);
	identify(*base2);
	
	delete base;
	delete base2;

	return 0;
}

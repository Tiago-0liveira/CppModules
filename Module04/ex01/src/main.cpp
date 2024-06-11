#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>

#include <iostream>

#define ANIMALS_NUM 4

int main()
{
	Animal *animals[ANIMALS_NUM];

	for (int i = 0; i < ANIMALS_NUM; i++)
	{
		if (i >= ANIMALS_NUM / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < ANIMALS_NUM; i++)
		animals[i]->makeSound();
	
	for (int i = 0; i < ANIMALS_NUM; i++)
		delete animals[i];

	return 0;
}


/* tests
int main()
{
	const Brain brain;

	*brain.getIdeas() = "aksmdkasmdkmasd";
	const Brain brain2(brain);
	const Brain brain3 = brain;
	*brain.getIdeas() = "123";
	std::cout << *brain.getIdeas() << std::endl;
	std::cout << *brain2.getIdeas() << std::endl;
	std::cout << *brain3.getIdeas() << std::endl;

	return 0;
}*/

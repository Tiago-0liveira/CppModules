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

	std::cout << "---------------------" << std::endl;
	
	const Brain brain;
	*brain.getIdeas() = "aksmdkasmdkmasd";
	
	const Brain brain2(brain);
	*brain2.getIdeas() = "ikasmd";
	
	const Brain brain3 = brain2;

	std::cout << *brain.getIdeas() << std::endl;
	std::cout << *brain2.getIdeas() << std::endl;
	std::cout << *brain3.getIdeas() << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
		tmp = basic;
		std::cout << tmp.getBrain() << std::endl;
	}
	std::cout << basic.getBrain() << std::endl;

	return 0;
}

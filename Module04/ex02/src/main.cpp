#include <AAnimal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>

#include <iostream>

#define ANIMALS_NUM 4

int main()
{
	Dog d;
	Cat c;

	d.makeSound();
	c.makeSound();

	return 0;
}


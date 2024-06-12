#include <AAnimal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>

#include <iostream>

int main()
{
	// uncomment this line to see that AAnimal is abstract and is not instantiable
	// AAnimal *animal = new AAnimal();

	Dog d;
 	Cat c;

	d.makeSound();
	c.makeSound();

	return 0;
}


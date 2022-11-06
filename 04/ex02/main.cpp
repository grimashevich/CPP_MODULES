#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << std::endl << std::endl;
    Cat matroskin = Cat();
    Cat tom = matroskin;
    matroskin.sayIdea(42);
    tom.sayIdea(42);

    return 0;
}
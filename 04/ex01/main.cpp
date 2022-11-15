#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void  additionalTest();

int main()
{

/*    additionalTest();
    return 0;*/

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << std::endl << std::endl;
    Cat *matroskin = new Cat();
    Cat *tom = new Cat();

    matroskin->sayIdea(42);
    tom->sayIdea(42);

    delete matroskin;
    delete tom;

    return 0;
}

void  additionalTest()
{
    Dog *dog1 = new Dog();
    Dog *dog2 = new Dog();

    dog1->sayIdea(0);
    dog2->sayIdea(0);

    *dog2 = *dog1;

    dog1->sayIdea(0);
    dog2->sayIdea(0);

    *dog1 = *dog1;

    delete dog1;
    delete dog2;
}
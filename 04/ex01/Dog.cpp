#include "Dog.hpp"

Dog::Dog()
{
    type = "dog";
    _brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog: Woof - woof!" << std::endl;
}

Dog &Dog::operator=(const Dog &source)
{
    Animal::operator=(source);
    this->_brain = new Brain();
    *this->_brain = *source._brain;
    return *this;
}

Dog::Dog(const Dog &source): Animal(source)
{
    *this = source;
}

void Dog::sayIdea(int index)
{
    std::cout << "- - - - - - - - -" << std::endl;
    std::cout << Animal::getType() << ": I have an idea! ";
    std::cout <<  _brain->GetIdea(index % IDEAS_COUNT) << std::endl;
    std::cout << "- - - - - - - - -" << std::endl;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

#include "Cat.hpp"

Cat::Cat()
{
    type = "cat";
    _brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat: Meeeeeooww!" << std::endl;
}

Cat::Cat(const Cat &source): Animal(source)
{
    *this = source;
}

Cat &Cat::operator=(const Cat &source)
{
    if (&source == this)
        return *this;
    Animal::operator=(source);
    delete this->_brain;
    this->_brain = new Brain();
    *this->_brain = *source._brain;
    return *this;
}

void Cat::sayIdea(int index)
{
    std::cout << "- - - - - - - - -" << std::endl;
    std::cout << Animal::getType() << ": I have an idea! ";
    std::cout <<  _brain->GetIdea(index % IDEAS_COUNT) << std::endl;
    std::cout << "- - - - - - - - -" << std::endl;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}



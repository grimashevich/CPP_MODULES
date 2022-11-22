#include <iostream>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    std::srand(std::time(NULL));
    for (int i = 0; i < 8; ++i)
    {
        Base *p = generate();
        identify(p);
        identify(*p);
        delete p;
        std::cout << std::endl;
    }
    return 0;
}

Base * generate(void)
{
    int rnd = std::rand() % 3;
    if (rnd == 0)
        return new A();
    else if (rnd == 1)
        return new B();
    return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "Type is A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "Type is B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "Type is C" << std::endl;
    else
        std::cout << "Type is unknown" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void) a;
        std::cout << "Type is A" << std::endl;
        return;
    }
    catch(std::exception &) {}
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void) b;
        std::cout << "Type is B" << std::endl;
        return;
    }
    catch(std::exception &) {}
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void) c;
        std::cout << "Type is C" << std::endl;
        return;
    }
    catch(std::exception &) {}
}
#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

int mainFromSubject();

int main(int, char**)
{

    const Array<int> n(5);
    Array<int> m;

    std::cout << "m size: " << m.Size() << std::endl;
    std::cout << "n size: " << n.Size() << std::endl;
    std::cout << "n[0]: " << n[0] << std::endl;

    std::cout << "m = n" << std::endl;
    m = n;
    std::cout << "m size: " << m.Size() << std::endl;
    m[1] = 17;
    std::cout << "m[1] = 17" << std::endl;
    std::cout << "m[1]: " <<m[1] << std::endl;
    std::cout << std::endl;
    mainFromSubject();
    return 0;
}

int mainFromSubject()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

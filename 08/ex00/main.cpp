#include <iostream>
#include <vector>
#include <ctime>
#include "easyfind.hpp"

#define ELEMENTS_COUNT 100

int main()
{
    std::vector<int> queue;
    std::vector<int>::iterator iter;

    std::srand(std::time(NULL));
    for (int i = 0; i < ELEMENTS_COUNT; ++i)
        queue.push_back(std::rand() % ELEMENTS_COUNT);
    std::sort(queue.begin(), queue.end());

    for (int i = 0; i < ELEMENTS_COUNT; ++i)
    {
        std::cout << queue[i] << " ";
    }
    std::cout << std::endl << std::endl;

    iter = easyFind(queue, 42);
    if (iter != queue.end())
        std::cout << "42 found" << std::endl;
    else
        std::cout << "42 not found" << std::endl;
    iter = easyFind(queue, 21);
    if (iter != queue.end())
        std::cout << "21 found" << std::endl;
    else
        std::cout << "21 not found" << std::endl;
    return 0;
}

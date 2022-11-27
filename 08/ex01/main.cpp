#include <iostream>
#include "Span.hpp"

void printSpans(Span &span);

int main()
{
    int size = 100;
    Span s1 = Span(size);

    std::cout << "Start adding numbers." << std::endl;
    srand(time(NULL));
    for (int i = 0; i <size; ++i)
    {
        int n = rand();
        s1.addNumber(n);
//        std::cout << n << " ";
    }
    std::cout << std::endl;
    std::cout << "Adding complete." << std::endl;
    printSpans(s1);
}

void printSpans(Span &span)
{
    try
    {
        uint minSpan = span.shortestSpan();
        std::cout << "Shortest span: " << minSpan << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    catch (std::runtime_error &e)
    {
        std::cout << "No spans are available" << std::endl;
        std::cout << e.what() << std::endl;
    }
}
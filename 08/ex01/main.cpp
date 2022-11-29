#include <iostream>
#include "Span.hpp"

void printSpans(Span &span);

int main()
{
    int size = 1e7;
    int numLimit = 1e9;

    Span s1 = Span(size);

    std::cout << "Start adding numbers." << std::endl;
    srand(time(NULL));
    for (int i = 0; i <size; ++i)
    {
        int n = rand() % numLimit;
        s1.addNumber(n);
        //std::cout << n << " ";
    }
    std::cout << "Adding complete." << std::endl;

    //Check = operator and leaks
    {
        Span s2 = Span(1);
        s2 = s1;
        (void) s2;
    }

    std::cout << "Start copying x4 numbers" << std::endl;
    Span s2 = Span(size * 4);
    s2.addRange(s1);
    s2.addRange(s1);
    s2.addRange(s2);
    std::cout << "End copying x4 numbers" << std::endl;

    std::cout << "Trying to add redunant element" << std::endl;
    try
    {
        s2.addNumber(0);
    }
    catch(std::overflow_error &e)
    {
        std::cout << "  Exception thrown" << std::endl;
        std::cout << "  " << e.what() << std::endl;
    }
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
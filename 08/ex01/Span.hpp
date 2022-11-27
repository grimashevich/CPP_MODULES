#ifndef EX01_SPAN_HPP
#define EX01_SPAN_HPP

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <limits>

typedef unsigned int uint;

#define NO_SPAN_ERROR "ERROR! No span found. Object must have more than 1 elements."
#define OVERFLOW_ERROR "ERROR! This object already stores the maximum number of integers."

class Span
{
private:
    std::vector<int> *_values;
    uint _maxSize;
    std::overflow_error _overflowError;
    std::runtime_error _noSpanError;
    bool _isSorted;
public:
    explicit Span(uint maxSize);

    Span(const Span &source);
    Span& operator=(const Span &source);

    void addNumber(int x);
    uint shortestSpan();
    uint longestSpan();
    void sort();
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    ~Span();
};

#endif //EX01_SPAN_HPP

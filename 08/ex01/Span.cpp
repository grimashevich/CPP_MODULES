#include "Span.hpp"


Span::Span(uint maxSize):   _values(new std::vector<int>()),
                            _maxSize(maxSize),
                            _overflowError(OVERFLOW_ERROR),
                            _noSpanError(NO_SPAN_ERROR),
                            _isSorted(true)
{

}

Span::Span(const Span &source):   _values(new std::vector<int>()),
                                  _maxSize(source._maxSize),
                                  _overflowError(source._overflowError.what()),
                                  _noSpanError(source._noSpanError.what()),
                                  _isSorted(source._isSorted)
{
    *this = source;
}

Span &Span::operator=(const Span &source)
{
    if (this == &source)
        return *this;
    this->_maxSize = source._maxSize;
    this->_isSorted = source._isSorted;
    delete this->_values;
    this->_values = new std::vector<int>();
    this->_values->insert(this->_values->begin(),
                          source._values->begin(),
                          source._values->end());
    return *this;
}

void Span::addNumber(int x)
{
    if (_values->size() >= _maxSize)
        throw _overflowError;
    _values->insert(_values->end(), x);
    _isSorted = false;
}

uint Span::shortestSpan()
{
    if (_values->size() < 2)
        throw _noSpanError;
    sort();
    uint minSpan = std::numeric_limits<unsigned int>::max();
    for (uint i = 0; i < _values->size() - 1; ++i)
    {
        uint curDiff = static_cast<uint>(_values->at(i + 1) - _values->at(i));
        if (curDiff < minSpan)
            minSpan  = curDiff;

        if (minSpan == 0)
            break;
    }
    return minSpan;
}

uint Span::longestSpan()
{
    if (_values->size() < 2)
        throw _noSpanError;
    sort();
    int min = *_values->begin();
    int max = *(_values->end() - 1);
    return max - min;
}

void Span::sort()
{
    if (_isSorted)
        return;
    std::cout << "start sorting..." << std::endl;
    std::sort(_values->begin(), _values->end());
    std::cout << "sorted" << std::endl;
    _isSorted = true;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (static_cast<uint>(end - begin) > _maxSize - _values->size())
        throw _overflowError;
    _values->insert(_values->end(), begin, end);
    _isSorted = false;
}

void Span::addRange(const Span &source)
{
    if (static_cast<uint>(source._values->end() -
                source._values->begin()) > _maxSize - _values->size())
        throw _overflowError;
    _values->insert(_values->end(), source._values->begin(), source._values->end());
    _isSorted = false;
}

Span::~Span()
{
    delete _values;
}





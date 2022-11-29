#ifndef EX02_MUTANTSTACK_HPP
#define EX02_MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
    MutantStack() {}

    MutantStack(const MutantStack<T> &source)
    {
        *this = source;
    }
    MutantStack<T>& operator=(const MutantStack<T> &source)
    {
        std::stack<T>::operator=(source);
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator
            reverse_iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }

    reverse_iterator rbegin()
    {
        return this->c.rbegin();
    }

    reverse_iterator rend()
    {
        return this->c.rend();
    }

    ~MutantStack()
    {

    }
};

#endif //EX02_MUTANTSTACK_HPP

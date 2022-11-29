#include "MutantStack.hpp"
#include <algorithm>

void anotherTest();

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl << " *** additional tests" << std::endl;
    anotherTest();
    return 0;
}

void anotherTest()
{
    MutantStack<int> myStack;
    typedef MutantStack<int>::iterator iter;
    typedef MutantStack<int>::reverse_iterator rIter;

    srand(time(NULL));
    for (int i = 0; i < 20; ++i)
        myStack.push(rand() % 100);

    for (iter myIter = myStack.begin(); myIter < myStack.end() ; ++myIter)
        std::cout << *myIter << " ";
    std::cout << std::endl;

    for (rIter myIter = myStack.rbegin(); myIter < myStack.rend(); ++myIter)
        std::cout << *myIter << " ";
    std::cout << std::endl;

    while (! myStack.empty())
        myStack.pop();
}
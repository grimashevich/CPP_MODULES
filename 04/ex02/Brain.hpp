#ifndef EX01_BRAIN_HPP
#define EX01_BRAIN_HPP

#define IDEAS_COUNT 100

#include <ctime>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

class Brain
{
private:
    std::string _ideas[IDEAS_COUNT];
    static std::string GetRandomIdea(int len);
public:
    Brain();

    Brain(const Brain& source);
    Brain& operator=(const Brain& source);

    std::string GetIdea(int index) const;

    void RefreshBrain(int ideasCount);
    ~Brain();
};


#endif //EX01_BRAIN_HPP

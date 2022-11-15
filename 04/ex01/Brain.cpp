#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
    RefreshBrain(IDEAS_COUNT);
}

std::string Brain::GetRandomIdea(int len)
{
    static int delta;
    static const char alphanum[] =
            "01`23456789                "
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    std::string idea;
    idea.reserve(len);
    srand((unsigned)time(NULL) * getpid() + delta++);
    for (int i = 0; i < len; ++i) {
        idea += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return idea;
}

void Brain::RefreshBrain(int ideasCount)
{
    srand((unsigned)time(NULL) * getpid());
    for (int i = 0; i < ideasCount; ++i)
    {
        _ideas[i % IDEAS_COUNT] = GetRandomIdea(rand() % 33 + 1);
    }
}

Brain::Brain(const Brain &source)
{
    *this = source;
}

std::string Brain::GetIdea(int index) const
{
    return _ideas[index % IDEAS_COUNT];
}

Brain &Brain::operator=(const Brain &source)
{
    for (int i = 0; i < IDEAS_COUNT; ++i)
    {
        _ideas[i] = source.GetIdea(i);
    }
    return *this;
}



Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

#include <string>
#include <iostream>

void print_str_to_upper(char *str);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i)
    {
        print_str_to_upper(argv[i]);
        if (i < argc - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void print_str_to_upper(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (std::isalpha(str[i]) && std::islower(str[i]))
            std::cout << char(toupper(str[i]));
        else
            std::cout << str[i];
        i++;
    }
}
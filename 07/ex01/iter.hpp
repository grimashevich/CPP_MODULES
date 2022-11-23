#ifndef EX01_ITER_HPP
#define EX01_ITER_HPP

template<typename A, typename L>
void iter(A *array, L length, void (*func)(A &item))
{
    for (L i = 0; i < length ; ++i)
        func(array[i]);
}

template<typename A, typename L>
void iter(A *array, L length, void (*func)(A const &item))
{
    for (L i = 0; i < length ; ++i)
        func(array[i]);
}

#endif //EX01_ITER_HPP

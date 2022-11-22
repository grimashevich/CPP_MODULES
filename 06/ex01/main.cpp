#include <iostream>
#include "DataStruct.hpp"
#include <stdint.h>

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

int main()
{
    uintptr_t serialized;
    Data *deserialized;

    Data *d = new Data;
    d->n = 42;
    d->s = "some string";

    serialized = serialize(d);
    deserialized = deserialize(serialized);

    std::cout << "d pointer: " << d << std::endl;
    std::cout << "d->n: " << d->n << std::endl;
    std::cout << "d->s: " << d->s << std::endl;
    std::cout << std::endl;
    std::cout << "serialized uintptr_t: " << serialized << std::endl;
    std::cout << std::endl;
    std::cout << "deserialized pointer: " << deserialized << std::endl;
    std::cout << "deserialized->n: " << deserialized->n << std::endl;
    std::cout << "deserialized->s: " << deserialized->s << std::endl;
    std::cout << std::endl;
    delete d;
    return 0;
}


uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

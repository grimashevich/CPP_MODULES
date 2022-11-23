#ifndef EX02_ARRAY_HPP
#define EX02_ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
private:
    T *_array;
    unsigned int _size;
    std::out_of_range OutOfRangeException;
public:
    Array();
    Array(unsigned int size);
    Array(const Array<T> &source);

    Array<T>& operator=(const Array<T> &source);
    T& operator[](unsigned int index);
    T operator[](unsigned int index) const;

    unsigned int Size() const;

    ~Array();
};

template<typename T>
Array<T>::Array(): _array(new T[0]), _size(0),
    OutOfRangeException("Index out of range")
{

}

template<typename T>
Array<T>::Array(unsigned int size): _array(new T[size]), _size(size),
    OutOfRangeException("Index out of range")
{
    for (unsigned int i = 0; i < size; ++i)
        _array[i] = T();
}

template<typename T>
Array<T>::Array(const Array<T> &source): _array(0), _size(0),
        OutOfRangeException("Index out of range")
{
    *this = source;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &source)
{
    if (&source == this)
        return *this;
    delete[] this->_array;
    this->_array = new T[source.Size()];
    for (unsigned int i = 0; i < source.Size(); ++i)
        this->_array[i] = source._array[i];
    this->_size = source._size;
    return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw OutOfRangeException;
    return _array[index];
}

template<typename T>
T Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw OutOfRangeException;
    return _array[index];
}

template<typename T>
unsigned int Array<T>::Size() const
{
    return _size;
}

template<typename T>
Array<T>::~Array()
{
    delete[] _array;
}


#endif //EX02_ARRAY_HPP

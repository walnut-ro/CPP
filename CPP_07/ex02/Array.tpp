#pragma once

#include <stdexcept>

template <typename T>
Array<T>::Array() : _array(nullptr), _len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _len(n) {}

template <typename T>
Array<T>::Array(const Array &copy) : _array(new T[copy._len]), _len(copy._len)
{
    for (size_t i = 0; i < _len; i++)
    {
        _array[i] = copy._array[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
    if (this != &copy)
    {
        T *tmp = new T[copy._len];
        for (size_t i = 0; i < copy._len; i++)
        {
            tmp[i] = copy._array[i];
        }
        delete[] _array;
        _array = tmp;
        _len = copy._len;
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _len;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _len)
    {
        throw std::out_of_range("Index is out of range");
    }
    return _array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _len)
    {
        throw std::out_of_range("Index is out of range");
    }
    return _array[index];
}

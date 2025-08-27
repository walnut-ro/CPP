#pragma once

#include <stdexcept>

template <typename T>
class Array
{
private:
    T *_array;
    unsigned int _len;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &copy);
    Array &operator=(const Array &copy);
    ~Array();

    unsigned int size() const;
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
};

#include "Array.tpp"

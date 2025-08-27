#pragma once
#include <iostream>

// Generic iter that applies a function to each element
template <typename T>
void iter(T *arr, size_t len, void (*fun)(T &))
{
    for (size_t i = 0; i < len; i++)
    {
        fun(arr[i]);
    }
}

// Const version (for functions taking const T&)
template <typename T>
void iter(T const *arr, size_t len, void (*fun)(T const &))
{
    for (size_t i = 0; i < len; i++)
    {
        fun(arr[i]);
    }
}

// Example modifier: add +1.5 to float
void plusFloat(float &num)
{
    num += 1.5f;
}

// Example modifier: prepend "Hello "
void prependHello(std::string &str)
{
    str = "Hello " + str;
}

// Example function template: print an element
template <typename T>
void printElement(const T &elem)
{
    std::cout << elem << std::endl;
}

// Wrapper: print an entire array
template <typename T>
void printArray(const T *arr, size_t len)
{
    iter(arr, len, printElement<T>);
}

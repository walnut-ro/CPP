#pragma once

#include <cstdint>
#include <iostream>

struct Data
{
    int input;
};

class Serializer
{
private:
    Serializer() = delete;
    Serializer(const Serializer &) = delete;
    Serializer &operator=(const Serializer &) = delete;
    ~Serializer() = delete;

public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

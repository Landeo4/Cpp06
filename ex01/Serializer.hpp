#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include <bits/stdc++.h>

struct Data
{
    int i;
};

class Serializer
{
    public:

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

    private:
    Serializer();
    Serializer(const Serializer & copy);
    Serializer&operator=(const Serializer & copy);
    ~Serializer();
};

#endif
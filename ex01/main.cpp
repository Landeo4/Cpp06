#include "Serializer.hpp"

int main()
{
    uintptr_t in = 5;
    Data *ptr;
    uintptr_t ou;

    std::cout << "voici la valeur ainsi que le pointeur de base ";
    std::cout << in << " " << &in << std::endl;
    ptr = Serializer::deserialize(in);
    std::cout << "voici la valeur ainsi que le pointeur de base ";
    std::cout << ptr << " " << &ptr << std::endl;
    ou = Serializer::serialize(ptr);
    std::cout << "voici la valeur ainsi que le pointeur de base ";
    std::cout << ou << " " << &ou << std::endl;
}

/*
je dois:
cree deux fonction: serialize et deserialize
serailize: prend un pointer et le convertis en unsigned int
deserialize: prend un unsigend int et le convertis en pointer Data

Cree une structure Data
utilise serialize sur l'adresse de l'object Data et le passer
en retour de deserialize. ensuite verifier si la valeur de retour de
deserialize est egal au pointer original

*/

/*
#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include <bits/stdc++.h>
#include "Data.hpp"

class Data
{
    public:
    Data();
    Data(const Data & copy);
    Data&operator=(const Data & copy);
    ~Data();
    private:
    
};

#endif
*/
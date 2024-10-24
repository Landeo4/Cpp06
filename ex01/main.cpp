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

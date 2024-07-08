#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer & copy)
{
    *this = copy;
}

Serializer &Serializer:: operator=(const Serializer & copy)
{
    if (this != &copy)
        *this = copy;
    return *this;
}

Serializer::~Serializer()
{

}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t da;
    da = reinterpret_cast<uintptr_t>(ptr);
    return da;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *ptr;
    ptr = reinterpret_cast<Data *>(raw);
    return ptr;
}

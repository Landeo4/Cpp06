#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter & copy)
{
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    if (this != &copy)
        *this = copy;
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert(std::string str)
{
    char cr = str[0];
    int it;
    double db;
    float ft;

    std::istringstream(str) >> it;
    db = static_cast<double>(str);
    // db = atof(str.c_str());
    // ft = atof(str.c_str());
    int verif_char = std::isprint(cr);
    if (cr != 0)
        std::cout << "char: " << cr << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: "<< it << std::endl;
    std::cout << "double: " << db << std::endl;
    std::cout << "float: " << ft << std::endl;
}

// en gros convertir dans les type, voir lequel est le bon
// le convertir dans les autres types puis afficher

//stoi -> int
//stod -> double
//atof -> float

// -inff
// +inff
// nanf(not a number)
// inf
// +inf
// nan
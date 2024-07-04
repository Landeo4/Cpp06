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
    if (str.length() > 1)
        return ;
    char cr = str[0];
    int it;
    std::istringstream(str) >> it;
    double db = atof(str.c_str());
    float ft = atof(str.c_str());
    std::cout << it << std::endl;
    std::cout << db << std::endl;
    std::cout << ft << std::endl;
    std::cout << cr << std::endl;
}

//stoi -> int
//stod -> double
//atof -> float
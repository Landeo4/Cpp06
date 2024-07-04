#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <bits/stdc++.h>

class ScalarConverter
{
    public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter & copy);
    ScalarConverter & operator=(const ScalarConverter & copy);
    ~ScalarConverter();

    static void convert(std::string str);
    private:
};

#endif
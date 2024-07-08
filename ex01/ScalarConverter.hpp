#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <bits/stdc++.h>

class ScalarConverter
{
    public:
    ~ScalarConverter();

    static void convert(std::string str);
    private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter & copy);
    ScalarConverter & operator=(const ScalarConverter & copy);
};

#endif
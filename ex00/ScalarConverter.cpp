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
    std::string test = " +inff";
    std::string tmp = "-inff" + test + " nan" " nanf" + " -inf" + " +inf";
    char c = str[0];
    int it;
    double db;
    float ft;
    int flag = 0;
    int check_part = 0;
    (void)c;

    if (str == "-inff" || str == "+inff" || str == "nan" || str == "nanf" || str == "-inf"
        || str == "+inf")
        check_part = 1;
    if (parsing(str, check_part) == 1)
    {
        std::cout << "Wrong input" << std::endl;
        return ;
    }
    if (str.find(".") < str.size())
    {
        std::cout << "je passe par premier if" << std::endl;
        if (str.find("f") < str.size())
        {
            flag = 1;
            std::cout << "float" << std::endl;
            std::istringstream(str) >> ft;
            db = static_cast<float>(ft);
            it = static_cast<int>(ft);
        }
        else
        {
            std::cout << "double" << std::endl;
            std::istringstream(str) >> db;
            ft = static_cast<double>(db);
            it = static_cast<int>(db);
        }
        c = str[0];
    }
    else if ((str[0] >= 48 && str[0] <= 57) || (str[0] >= 48 && str[0] <= 57) || str[0] == '-')
    {
        std::cout << "int" << std::endl;
        std::istringstream(str) >> it;
        db = static_cast<float>(it);
        ft = static_cast<double>(it);
        c = str[0];
    }
    else
    {
        std::cout << "je suis char" << std::endl;
        c = str[0];
        it = static_cast<int>(c);
        db = static_cast<double>(c);
        ft = static_cast<float>(c);
    }
    int last = tmp.find(str);
    std::cout << last << std::endl;

    int sb = atoi(str.c_str());

    if (check_part == 1 || sb <= 0 || sb >= 127)
        std::cout << "char: impossible" << std::endl;
    else if (sb >= 0 && sb <= 127 && !isprint(sb))
        std::cout << "char: Non displayable" << std::endl;
    else if (str.size() < 2 && !isdigit(c))
        std::cout << "char: " << static_cast<int>(c) << std::endl;
    else 
        std::cout << "char: " << static_cast<char>(atoi((str.c_str()))) << std::endl;
    // pour les char

    // pour les int

    if (check_part == 1)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << it << std::endl;

    // pour les float

    if (str == "nan" || str == "nanf")
        std::cout << "float: nanf" << std::endl;
    else if (str == "-inf" || str == "-inff")
        std::cout << "float: -inff" << std::endl;
    else if (str == "+inf" || str == "+inff")
        std::cout << "float: +inff" << std::endl;
    else
    {
        size_t pos = str.find(".");
        if ((pos + 1 >= str.size() || pos >= str.size()) || (str[pos + 1] == 'f' || str[pos + 1] == '0'))
            std::cout << "float: " << ft <<  ".0f" << std::endl;
        else
        std::cout << "float: " << ft <<  "f" << std::endl;
    }

    // pour les double
    if (str == "nanf" || str == "nan")
        std::cout << "double: nan" << std::endl;
    else if (str == "-inff" || str == "-inf")
        std::cout << "double: -inf" << std::endl;
    else if (str == "+inff" || str == "+inf")
        std::cout << "double: +inf" << std::endl;
    else
    {
        // if (str.find(".") < str.size() && str.find(".0") > str.size())
        size_t pos = str.find(".");
        if ((pos + 1 >= str.size() || pos  >= str.size()) || (str[pos + 1] == 'f' || str[pos + 1] == '0'))
            std::cout << "double: " << db << ".0" << std::endl;
        else
            std::cout << "double: " << db << std::endl;
    }

    // else if (str.find(".") < str.size())
    // {
    //     std::cout << "double: " << db << std::endl;
    // }
    // else
    //     std::cout << "double: " << db << ".0" << std::endl;
}

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
    if (str.length() == 1 && !isdigit(str[0]))
    {
        // gerer l'affichage.
        std::cout << "char: " << str[0] << std::endl;
        std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
        return ;
    }
    
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
        if (str.find("f") < str.size())
        {
            flag = 1;
            std::istringstream(str) >> ft;
            db = static_cast<double>(ft);
            it = static_cast<int>(ft);
        }
        else
        {
            std::istringstream(str) >> db;
            ft = static_cast<float>(db);
            it = static_cast<int>(db);
        }
        c = static_cast<int>(it);
    }
    else if ((str[0] >= 48 && str[0] <= 57) || (str[0] >= 48 && str[0] <= 57) || str[0] == '-')
    {
        std::cout << "je rentre dans int ";
        std::istringstream(str) >> it;
        db = static_cast<double>(it);
        ft = static_cast<float>(it);
        c = static_cast<int>(it);
    }
    else
    {
        std::cout << "fils de pute";
        c = str[0];
        it = static_cast<int>(c);
        db = static_cast<double>(c);
        ft = static_cast<float>(c);
    }
    int last = tmp.find(str);
    std::cout << last << std::endl;


// regler le char
// 1.0
    // pour les char
    c = atoi(str.c_str());
    if (c < 0 || c > 127 || check_part == 1)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(c) << std::endl;

    // pour les int

    if (check_part == 1)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << it << std::endl;

    // pour les float

    size_t dot = 0, f = 0;
    dot = str.find(".");
    f = str.find('f');
    // std::cout << dot << " dot puis size " << str.size() << std::endl;
    std::cout << std::endl;
    // std::cout << "str + 1 " << str[dot + 1] << std::endl;
    // std::cout << "voici f " << f << " ";
    if (str == "nan" || str == "nanf")
        std::cout << "float: nanf" << std::endl;
    else if (str == "-inf" || str == "-inff")
        std::cout << "float: -inff" << std::endl;
    else if (str == "+inf" || str == "+inff")
        std::cout << "float: +inff" << std::endl;
    if (f < str.size())
    {
        if (dot >= str.size()) //45.0f
            std::cout << "float: " << ft <<  ".0f" << std::endl << "double: " << db <<  ".0" << std::endl;
        else if (str[f - 1] == '0' && f - 2 == dot) // 45f
            std::cout << "float: " << ft <<  ".0f" << std::endl << "double: " << db <<  ".0" << std::endl;
        else if (dot + 1 != '0') // 45.45f
            std::cout << "float: " << ft << "f" << std::endl << "double: " << db << std::endl;
        // tous les f
    }
    else
    {
        std::cout << "je passe par le reste " << std::endl;// 45
        if (f >= str.size() && dot >= str.size())
            std::cout << "float: " << ft <<  ".0f" << std::endl << "double: " << db <<  ".0" << std::endl;
        else if (str[dot + 1] == '0' && dot + 2 == str.size()) // 45.0
            std::cout << "float: " << ft <<  ".0f" << std::endl << "double: " << db <<  ".0" << std::endl;
        else
            std::cout << "float: " << ft << "f" << std::endl << "double: " << db << std::endl;
        //  if (dot + 2 < str.size() && (str[dot + 2] != '0' && str[dot + 2] != 'f')) // 45.04
        // le reste
    }
    // 45.0
    // 45.04
    // 45
    // 45.04f
    // 45f

    // else if (f == 1)
    //     std::cout << "float: " << ft <<  "f" << std::endl;
    // else
    //     std::cout << "float: " << ft <<  ".0f" << std::endl;
    // else
    // {
        // size_t pos = str.find(".");
        // // std::cout << pos;
        // if ((pos + 1 >= str.size() || pos >= str.size()) || ((str[pos + 1] == 'f' && pos + 2 >= str.size()) || (str[pos + 1] == '0')))
        // {
        //     if (((str[pos + 2] <= 48 && str[pos + 2] >= 57) || str[pos + 2] == 'f') || pos > str.size())
        //         std::cout << "float: " << ft <<  ".0f" << std::endl;
        //     else
        //         std::cout << "float: " << ft <<  "f" << std::endl;
        // }
        // else
        //     std::cout << "float: " << ft <<  "f" << std::endl;
    // }

    // pour les double
    if (str == "nanf" || str == "nan")
        std::cout << "double: nan" << std::endl;
    else if (str == "-inff" || str == "-inf")
        std::cout << "double: -inf" << std::endl;
    else if (str == "+inff" || str == "+inf")
        std::cout << "double: +inf" << std::endl;
    // else
    // {
    //     size_t pos = str.find(".");
    //     if ((pos + 1 >= str.size() || pos >= str.size()) || ((str[pos + 1] == 'f' && pos + 2 >= str.size()) || (str[pos + 1] == '0')))
    //     {
    //         if (((str[pos + 2] <= 48 && str[pos + 2] >= 57) || str[pos + 2] == 'f') || pos > str.size())
    //             std::cout << "double: " << ft <<  ".0" << std::endl;
    //         else
    //             std::cout << "double: " << ft << std::endl;
    //     }
    //     else
    //         std::cout << "double: " << ft << std::endl;
    // }

    // else if (str.find(".") < str.size())
    // {
    //     std::cout << "double: " << db << std::endl;
    // }
    // else
    //     std::cout << "double: " << db << ".0" << std::endl;
}

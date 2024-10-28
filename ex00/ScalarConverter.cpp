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
    else if (flag == 1 && (str.find(".") < str.size() && str.find(".0") > str.size()))
        std::cout << "float: " << ft << "f" << std::endl;
    else
        std::cout << "float: " << ft <<  ".0f" << std::endl;

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
        int pos = str.find(".");
        if (pos + 1 > str.size())
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

// void ScalarConverter::convert(std::string str)
// {
//     char cr = str[0];
//     int it;
//     double db;
//     float ft;

//     // std::cout << "voici input" << str << std::endl;
//     std::istringstream(str) >> it;
//     std::stringstream(str) >> db;
//     ft = static_cast<float>(db);

//     // verification du char
//     int stop = str.find(".");
//     if (str == "-inff" || str == "+inff" || str == "nan" || str == "nanf" || str == "-inf"
//         || str == "+inf")
//     {
//         std::cout << "char : impossible" << std::endl;
//     }
//     else if (stop == 1)
//         std::cout << "char: " << '*' << std::endl;
//     else if (str[0] >= 48 && str[0] <= 57)
//         std::cout << "char : Non displayable" << std::endl;
//     else if (std::isprint(cr) != 0)
//         std::cout << "char: " << cr << std::endl;
//     // else if (last == -1 || (str.length() > 1 && str[0] <= 48 && str[0] >= 57))
//         // std::cout << "char: impossible" << std::endl;

//     //verification du int

//     if (last != -1)
// 		std::cout << "int: impossible" << std::endl;
// 	else
// 		std::cout << "int: " << it << std::endl;

//     //verif du float
//     // std::cout << "voici last " << last << " et lost " << stop << std::endl;
//     if (last != -1)
//     {
//         if (str == "nan")
//             std::cout << "float: nanf" << std::endl;
//         else if (str == "-inf")
//             std::cout << "float: -inff" << std::endl;
//         else if (str == "+inf")
//             std::cout << "float: +inff" << std::endl;
//         else
//             std::cout << "float: " << str << std::endl;
//     }
//     else
//         std::cout << "float: " << ft << ".0f"<< std::endl;
//     // else if (stop != -1)
//     // else
//         // std::cout << "float: " << ft << "f" << std::endl;

//     //verif du double
//     last = tmp.find(str);
//     // std::cout << "voici last " << last << " et lost " << stop << std::endl;
//     if (last != -1)
//     {
//         if (str == "nanf")
//             std::cout << "double: nan" << std::endl;
//         else if (str == "-inff")
//             std::cout << "double: -inf" << std::endl;
//         else if (str == "+inff")
//             std::cout << "double: +inf" << std::endl;
//         else
//             std::cout << "double: " << str << std::endl;
//     }
//     else
//         std::cout << "double: " << db << ".0"<< std::endl;
//     // else if (stop == -1)
//         // std::cout << "double: " << db << std::endl;
//     // std::cout << "double: " << db << std::endl;
// }

// en gros convertir dans les type, voir lequel est le bon
// donc trouver method pour savoir quel type est le bon
// le convertir dans les autres types puis afficher

// pour le float, le bon type finis par un f: 42.0f
// pour le double, il y a un point mais pas le f
// pour le int ya rien a part le nombre
// pour le char il y a autre chose qu'un nombre

//stoi -> int
//stod -> double
//atof -> float

// -inff
// +inff
// nanf(not a number)
// inf
// +inf
// nan
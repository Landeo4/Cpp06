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
    char cr = str[0];
    int it;
    double db;
    float ft;

    // std::cout << "voici input" << str << std::endl;
    std::istringstream(str) >> it;
    std::stringstream(str) >> db;
    ft = static_cast<float>(db);
    int last = tmp.find(str);
    std::cout << last << std::endl;
    // verification du char
    if (str[0] >= 90 && str[0] <= 65)
        std::cout << "jepasseici";
    if (str[0] >= 48 && str[0] <= 57)
        std::cout << "char : Non displayable" << std::endl;
    else if (last == -1 || (str.length() > 1 && str[0] <= 48 && str[0] >= 57))
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(cr) != 0)
        std::cout << "char: " << cr << std::endl;
    //verification du int

    if (last != -1)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << it << std::endl;

    int stop = str.find(".");
    if (last != -1)
    {
        std::cout << "float: ";
        while (tmp[last] != ' ')
        {
            std::cout << tmp[last];
            last++;
        }
        std::cout << std::endl;
    }
    else if (stop == -1)
        std::cout << "float: " << ft << ".0f"<< std::endl;
    else
        std::cout << "float: " << ft << "f" << std::endl;

    last = tmp.find(str);
    if (last != -1)
    {
        std::cout << "double: ";
        while (tmp[last] != ' ')
        {
            std::cout << tmp[last];
            last++;
        }
        std::cout << std::endl;
    }
    else if (stop == -1)
        std::cout << "double: " << db << ".0"<< std::endl;
    else
        std::cout << "double: " << db << std::endl;
    // std::cout << "double: " << db << std::endl;
}

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
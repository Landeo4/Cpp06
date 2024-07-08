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
    std::string tmp = "-inff" + test + " nan" " nanf" + " inf" + " +inf";
    char cr = str[0];
    int it;
    double db;
    float ft;

    std::istringstream(str) >> it;
    std::stringstream(str) >> db;
    ft = static_cast<float>(db);
    int last = tmp.find(str);
    std::cout << last << std::endl;
    // verification du char
    if (last != -1)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(cr) != 0)
        std::cout << "char: " << cr << std::endl;
    else
        std::cout << "char : Non displayable" << std::endl;
    //verification du int

    if (last != -1)
		std::cout << "int: impossible" << std::endl;
	else if (std::isprint(it) != 0)
		std::cout << "int: " << it << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

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
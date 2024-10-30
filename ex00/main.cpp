#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "wrong argument" << std::endl;
        return 0;
    }
    std::string ar = std::string(argv[1]);
    ScalarConverter::convert(ar);
}

// je dois check s'il y a un char seul ou un nombre seul (seul exception -)

bool parsing(std::string str, int check_part)
{
    if (check_part == 1)
        return 0;
    size_t i = 0;
    int check = 0;
    int tmp = 0;
    int tmp2 = 0;
    while (str[i])
    {
        if (tmp == 1)
            return 1;
        if (isalpha(str[i]))
            tmp = 1;
        else if (str[i] == '.')
        {
            if (tmp2 == 1)
                return 1;
            tmp2 = 1;
        }
        i++;
    }
    i = 0;
    tmp = 0;
    while (str[i])
    {
        // si lettre
        if ((isalpha(str[i]) || (str[i] == '.' && i + 1 == str.size())) && tmp <= 1)
        {
            if (tmp == 1)
                return 1;
            if (str[i] == 'f')
                tmp = 1;
            else if (check == 1 || check == 2)
                return 1;
            size_t t = str.find(".");
            if (t <= str.size() && (str[t + 1] <= 48 && str[t + 1] >= 57))
                return 1;
            else if (t <= str.size())
            {
                while (str[t])
                {
                    if (str[t] >= 48 && str[t] <= 57)
                        t++;
                    if (str[t] == 'f' && (str[t - 1] >= 48 && str[t - 1] <= 57))
                        return 0;
                    t++;
                }
                return 1;
            }
            check = 1;
        }
        else if (str[i] >= 48 && str[i] <= 57)
        {
            // si nb
            if (check == 1)
                return 1;
            check = 2;
        }
        i++;
    }
    return 0;
}

/*
** ShipWreck engine, 2020
** main.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>

void cat_file(const char *filename)
{
    std::ifstream file(filename);
    std::string str;

    if (!file)
        std::cerr << "my_cat: file: No such file or directory" << std::endl;
    else {
        while (std::getline(file, str))
            std::cout << str << std::endl;
        file.close();
    }
}

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "my_cat: Usage: ./my_cat file [...]" << std::endl;
    for (int ctr = 1; av[ctr] != NULL; ctr += 1)
        cat_file(av[ctr]);
    return (0);
}
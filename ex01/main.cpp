/*
** ShipWreck engine, 2020
** main.c
*/

#include <iostream>
#include <fstream>
#include <iomanip>

void getFahrenheit(double temperature)
{
    std::string resultTemp;

    temperature = (temperature * 9 / 5) + 32;
    resultTemp = std::to_string(temperature);
    std::cout
        << std::setw(16)
        << resultTemp.substr(0, resultTemp.size() - 3)
        << std::resetiosflags(std::ios_base::basefield);
    std::cout
        << std::setw(16)
        << "Fahrenheit"
        << std::endl
        << std::resetiosflags(std::ios_base::basefield);
}

void getCelsius(double temperature)
{
    std::string resultTemp;

    temperature = 5.0 / 9.0 * (temperature - 32);
    resultTemp = std::to_string(temperature);
    std::cout
        << std::setw(16)
        << resultTemp.substr(0, resultTemp.size() - 3)
        << std::resetiosflags(std::ios_base::basefield);
    std::cout
        << std::setw(16)
        << "Celsius"
        << std::endl
        << std::resetiosflags(std::ios_base::basefield);
}

int main(void)
{
    double temperature;
    std::string scale;

    std::cin >> temperature;
    std::cin >> scale;
    if (scale == "Celsius")
        getFahrenheit(temperature);
    else if (scale == "Fahrenheit")
        getCelsius(temperature);
    return (0);
}
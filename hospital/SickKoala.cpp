/*
** ShipWreck engine, 2020
** SickKoala.cpp
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(const std::string& name) :
m_name(name)
{}

SickKoala::~SickKoala()
{
    std::cout
        << "Mr."
        << m_name
        << ": Kreooogg!! I'm cuuuured!"
        << std::endl;
}

void SickKoala::poke() const
{
    std::cout
        << "Mr."
        << m_name
        << ": Gooeeeeerrk!!"
        << std::endl;
}

bool SickKoala::takeDrug(const std::string& drug) const
{
    if (drug == "Mars")
        std::cout
            << "Mr."
            << m_name
            << ": Mars, and it kreogs!"
            << std::endl;
    else if (drug == "Kinder")
        std::cout
            << "Mr."
            << m_name
            << ": There is a toy inside!"
            << std::endl;
    else {
        std::cout
            << "Mr."
            << m_name
            << ": Goerkreog!"
            << std::endl;
        return (false);
    }
    return (true);
}

void SickKoala::overDrive(std::string str) const
{
    for (std::size_t check = 0
    ;(check = str.find("Kreog", check)) != std::string::npos
    && check < str.size()
    ; check += 1)
        str = str.replace(check, 5, "1337");
    std::cout
            << "Mr."
            << m_name
            << ": "
            << str
            << std::endl;
}

const std::string& SickKoala::getName() const
{
    return (m_name);
}
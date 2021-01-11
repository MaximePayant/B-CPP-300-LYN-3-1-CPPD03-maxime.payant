/*
** ShipWreck engine, 2020
** KoalaDoctor.cpp
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(const std::string& name) :
m_name(name)
{
    std::cout
        << "Dr.["
        << m_name
        << "]: I'm Dr.["
        << m_name
        << "]! How do you kreog?"
        << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{}

static void write_report(const std::string& filename)
{
    std::ofstream file(filename);

    file << drugs[rand() % 5];
}

void KoalaDoctor::diagnose(const SickKoala *koala) const
{
    std::cout
        << "Dr.["
        << m_name
        << "]: So what's goerking you Mr.["
        << koala->getName()
        << "]?"
        << std::endl;
    koala->poke();
    write_report(koala->getName() + ".report");
}

void KoalaDoctor::timeCheck(void)
{
    if (m_isWorking) {
        std::cout
            << "Dr.["
            << m_name
            << "]: Time to go home to my eucalyptus forest!"
            << std::endl;
        m_isWorking = false;
    }
    else {
        std::cout
            << "Dr.["
            << m_name
            << "]: Time to get to work!"
            << std::endl;
        m_isWorking = true;
    }
}
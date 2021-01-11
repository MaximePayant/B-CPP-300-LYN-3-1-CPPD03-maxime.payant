/*
** ShipWreck engine, 2020
** KoalaNurse.cpp
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id) :
m_id(id),
m_isWorking(false)
{}

KoalaNurse::~KoalaNurse()
{
    std::cout
        << "Nurse ["
        << m_id
        << "]: Finally some rest!"
        << std::endl;
}

void KoalaNurse::giveDrug(const std::string& drug, SickKoala *koala) const
{
    koala->takeDrug(drug);
}

const std::string KoalaNurse::readReport(const std::string& reportName) const
{
    std::ifstream file(reportName);
    std::string drug;
    std::size_t offset;
    std::size_t len;
    std::string koala;

    if (!file)
        return ("");
    drug = std::string((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    offset = reportName.find_last_of('/');
    len = reportName.find_last_of('.') - offset;
    koala = reportName.substr((offset > 0 ? offset + 1 : offset), len - 1);
    std::cout
        << "Nurse ["
        << m_id
        << "]: Kreog! Mr.["
        << koala
        << "] needs a ["
        << drug
        << "]!"
        << std::endl;
    return (file.close(), drug);
}

void KoalaNurse::timeCheck(void)
{
    if (m_isWorking) {
        std::cout
            << "Nurse ["
            << m_id
            << "]: Time to go home to my eucalyptus forest!"
            << std::endl;
        m_isWorking = false;
    }
    else {
        std::cout
            << "Nurse ["
            << m_id
            << "]: Time to get to work!"
            << std::endl;
        m_isWorking = true;
    }
}
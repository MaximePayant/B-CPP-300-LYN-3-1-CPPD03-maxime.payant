/*
** ShipWreck engine, 2020
** KoalaDoctor.hpp
*/

#ifndef KOALA_DOCTOR_HPP
#define KOALA_DOCTOR_HPP

#include <iostream>
#include <fstream>

#include "SickKoala.hpp"

const std::string drugs[] =
{
    "Mars",
    "Kinder",
    "Crunch",
    "Maroilles",
    "Eucalyptus_leaf"
};

class KoalaDoctor
{
    private:
        std::string m_name;
        bool m_isWorking;

    public:
        KoalaDoctor() = delete;
        KoalaDoctor(KoalaDoctor const&) = delete;
        KoalaDoctor(KoalaDoctor&&) = delete;
        KoalaDoctor(const std::string& name);
        ~KoalaDoctor();

        void diagnose(const SickKoala *koala) const;
        void timeCheck();
};

#endif // KOALA_DOCTOR_HPP
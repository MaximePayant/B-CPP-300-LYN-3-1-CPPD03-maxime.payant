/*
** ShipWreck engine, 2020
** SickKoala.hpp
*/

#ifndef SICK_KOALA_HPP
#define SICK_KOALA_HPP

#include <iostream>

class SickKoala
{

    private:
        std::string m_name;

    public:
        SickKoala() = delete;
        SickKoala(SickKoala const& ) = delete;
        SickKoala(SickKoala&& ) = delete;
        SickKoala(const std::string& name);
        ~SickKoala();

        void poke() const;
        bool takeDrug(const std::string& drug) const;
        void overDrive(std::string str) const;

}; // class SickKoala

#endif // SICK_KOALA_HPP
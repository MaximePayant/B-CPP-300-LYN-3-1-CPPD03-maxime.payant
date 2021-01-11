/*
** ShipWreck engine, 2020
** KoalaNurse.hpp
*/

#ifndef KOALA_NURSE_HPP
#define KOALA_NURSE_HPP

#include "SickKoala.hpp"
#include <iostream>
#include <fstream>

class KoalaNurse
{

    private:
        int m_id;
        bool m_isWorking;

    public:
        KoalaNurse(int id);
        ~KoalaNurse();

        void giveDrug(const std::string& drug, SickKoala *koala) const;
        const std::string readReport(const std::string& reportName) const;
        void timeCheck(void);

};

#endif // KOALA_NURSE_HPP
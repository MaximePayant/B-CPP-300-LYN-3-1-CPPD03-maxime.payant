/*
** ShipWreck engine, 2020
** Hospital.hpp
*/

#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include "SickKoalaList.hpp"
#include "KoalaNurseList.hpp"
#include "KoalaDoctorList.hpp"

class Hospital
{

    private:
        SickKoalaList *m_koalaList;
        KoalaNurseList *m_nurseList;
        KoalaDoctorList *m_doctorList;

    public:
        Hospital();
        ~Hospital();

        void addSick(SickKoalaList *koala);
        void addNurse(KoalaNurseList *nurse);
        void addDoctor(KoalaDoctorList *doctor);
        void run();
};

#endif // HOSPITAL_HPP
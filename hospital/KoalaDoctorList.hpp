/*
** ShipWreck engine, 2020
** KoalaDoctorList.hpp
*/

#ifndef KOALA_DOCTOR_LIST_HPP
#define KOALA_DOCTOR_LIST_HPP

#include "KoalaDoctor.hpp"

class KoalaDoctorList
{
    private:
        KoalaDoctor *m_value;
        KoalaDoctorList *m_next;

    public:
        KoalaDoctorList() = delete;
        KoalaDoctorList(KoalaDoctorList const&) = delete;
        KoalaDoctorList(KoalaDoctorList&&) = delete;

        KoalaDoctorList(KoalaDoctor *koala);
        ~KoalaDoctorList();

        bool isEnd() const;
        void append(KoalaDoctorList *koala);
        KoalaDoctorList *getFromName(const std::string& name);
        KoalaDoctorList *remove(KoalaDoctorList *koala);
        KoalaDoctorList *removeFromName(const std::string& name);
        KoalaDoctor *getContent() const;
        KoalaDoctorList *getNext() const;
        void dump();
};

#endif // KOALA_DOCTOR_LIST_HPP
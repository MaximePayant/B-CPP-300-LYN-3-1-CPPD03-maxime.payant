/*
** ShipWreck engine, 2020
** SickKoalaList.hpp
*/

#ifndef SICK_KOALA_LIST_HPP
#define SICK_KOALA_LIST_HPP

#include "SickKoala.hpp"

class SickKoalaList
{
    private:
        SickKoala *m_value;
        SickKoalaList *m_next;

    public:
        SickKoalaList() = delete;
        SickKoalaList(SickKoalaList const&) = delete;
        SickKoalaList(SickKoalaList&&) = delete;
        SickKoalaList(SickKoala *koala);
        ~SickKoalaList();
        bool isEnd() const;
        void append(SickKoalaList *koala);
        SickKoalaList *getFromName(const std::string& name);
        SickKoalaList *remove(SickKoalaList *koala);
        SickKoalaList *removeFromName(const std::string& name);
        SickKoala *getContent() const;
        SickKoalaList *getNext() const;
        void dump();
};

#endif // SICK_KOALA_LIST_HPP
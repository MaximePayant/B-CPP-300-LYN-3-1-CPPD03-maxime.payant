/*
** ShipWreck engine, 2020
** KoalaNurseList.hpp
*/

#ifndef KOALA_NURSE_LIST_HPP
#define KOALA_NURSE_LIST_HPP

#include "KoalaNurse.hpp"

class KoalaNurseList
{
    private:
        KoalaNurse *m_value;
        KoalaNurseList *m_next;

    public:
        KoalaNurseList() = delete;
        KoalaNurseList(KoalaNurseList const&) = delete;
        KoalaNurseList(KoalaNurseList&&) = delete;

        KoalaNurseList(KoalaNurse *koala);
        ~KoalaNurseList();

        bool isEnd() const;
        void append(KoalaNurseList *koala);
        KoalaNurse *getFromID(int id);
        KoalaNurseList *remove(KoalaNurseList *koala);
        KoalaNurseList *removeFromID(int id);
        KoalaNurse *getContent() const;
        KoalaNurseList *getNext() const;
        void dump();
};

#endif // KOALA_NURSE_LIST_HPP
/*
** ShipWreck engine, 2020
** KoalaNurseList.cpp
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *koala)
{
    m_value = koala;
    m_next = NULL;
}

KoalaNurseList::~KoalaNurseList()
{}

bool KoalaNurseList::isEnd() const
{
    if (m_next == NULL)
        return (true);
    return (false);
}

void KoalaNurseList::append(KoalaNurseList *koala)
{
    KoalaNurseList *tmp = this;

    if (tmp == NULL)
        tmp = koala;
    else {
        while (tmp->m_next != NULL)
            tmp = tmp->m_next;
        tmp->m_next = koala;
    }
}

KoalaNurseList *KoalaNurseList::getFromID(int id)
{
    KoalaNurseList *tmp = this;

    while (tmp != NULL) {
        if (tmp->m_value->getID() == id)
            return (tmp);
        tmp = tmp->m_next;
    }
    return (NULL);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *koala)
{
    KoalaNurseList *prev = this;
    KoalaNurseList *tmp = m_next;

    if (this == koala)
        return (m_next);
    while (tmp != koala) {
        if (tmp == NULL)
            return (this);
        prev = tmp;
        tmp = tmp->m_next;
    }
    prev->m_next = tmp->m_next;
    return (this);
}

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
    KoalaNurseList *prev = this;
    KoalaNurseList *tmp = m_next;

    if (m_value->getID() == id)
        return (m_next);
    while (tmp && tmp->m_value->getID() != id) {
        if (tmp == NULL)
            return (this);
        prev = tmp;
        tmp = tmp->m_next;
    }
    prev->m_next = tmp->m_next;
    return (this);
}

void KoalaNurseList::dump()
{
    KoalaNurseList *tmp = this;

    std::cout << "Nurses: ";
    while (tmp) {
        if (tmp->m_value)
            std::cout << tmp->m_value->getID();
        else
            std::cout << "[nullptr]";
        if (tmp->m_next)
            std::cout << ", ";
        else
            std::cout << "." << std::endl;
        tmp = tmp->m_next;
    }
}
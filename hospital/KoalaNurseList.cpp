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

    if (tmp->m_value == NULL)
        tmp->m_value = koala->m_value;
    else {
        while (tmp->m_next != NULL) {
            if (tmp == koala)
                return;
            tmp = tmp->m_next;
        }
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

    koala->m_next = NULL;
    if (this == koala)
        return (tmp);
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

    getFromID(id)->m_next = NULL;
    if (m_value->getID() == id)
        return (tmp);
    while (tmp && tmp->m_value->getID() != id) {
        if (tmp == NULL)
            return (this);
        prev = tmp;
        tmp = tmp->m_next;
    }
    prev->m_next = tmp->m_next;
    return (this);
}

KoalaNurse *KoalaNurseList::getContent() const
{
    return (m_value);
}

KoalaNurseList *KoalaNurseList::getNext() const
{
    return (m_next);
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
            std::cout << ".";
        tmp = tmp->m_next;
    }
    std::cout << std::endl;
}
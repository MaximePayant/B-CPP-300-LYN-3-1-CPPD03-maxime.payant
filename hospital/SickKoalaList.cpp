/*
** ShipWreck engine, 2020
** SickKoalaList.cpp
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala)
{
    m_value = koala;
    m_next = NULL;
}

SickKoalaList::~SickKoalaList()
{}

bool SickKoalaList::isEnd() const
{
    if (m_next == NULL)
        return (true);
    return (false);
}

void SickKoalaList::append(SickKoalaList *koala)
{
    SickKoalaList *tmp = this;

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

SickKoala *SickKoalaList::getFromName(const std::string& name)
{
    SickKoalaList *tmp = this;

    while (tmp != NULL) {
        if (tmp->m_value->getName() == name)
            return (tmp->m_value);
        tmp = tmp->m_next;
    }
    return (NULL);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *koala)
{
    SickKoalaList *prev = this;
    SickKoalaList *tmp = m_next;

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

SickKoalaList *SickKoalaList::removeFromName(const std::string& name)
{
    SickKoalaList *prev = this;
    SickKoalaList *tmp = m_next;

    if (m_value->getName() == name)
        return (tmp);
    while (tmp && tmp->m_value->getName() != name) {
        if (tmp == NULL)
            return (this);
        prev = tmp;
        tmp = tmp->m_next;
    }
    prev->m_next = tmp->m_next;
    return (this);
}

SickKoala *SickKoalaList::getContent() const
{
    return (m_value);
}

SickKoalaList *SickKoalaList::getNext() const
{
    return (m_next);
}

void SickKoalaList::dump()
{
    SickKoalaList *tmp = this;

    std::cout << "Patients: ";
    while (tmp) {
        if (tmp->m_value)
            std::cout << tmp->m_value->getName();
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
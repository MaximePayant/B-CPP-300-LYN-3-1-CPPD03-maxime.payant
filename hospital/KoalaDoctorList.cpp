/*
** ShipWreck engine, 2020
** KoalaDoctorList.cpp
*/

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *koala)
{
    m_value = koala;
    m_next = NULL;
}

KoalaDoctorList::~KoalaDoctorList()
{}

bool KoalaDoctorList::isEnd() const
{
    if (m_next == NULL)
        return (true);
    return (false);
}

void KoalaDoctorList::append(KoalaDoctorList *koala)
{
    KoalaDoctorList *tmp = this;

    if (tmp == NULL)
        tmp = koala;
    else {
        while (tmp->m_next != NULL)
            tmp = tmp->m_next;
        tmp->m_next = koala;
    }
}

KoalaDoctorList *KoalaDoctorList::getFromName(const std::string& name)
{
    KoalaDoctorList *tmp = this;

    while (tmp != NULL) {
        if (tmp->m_value->getName() == name)
            return (tmp);
        tmp = tmp->m_next;
    }
    return (NULL);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *koala)
{
    KoalaDoctorList *prev = this;
    KoalaDoctorList *tmp = m_next;

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

KoalaDoctorList *KoalaDoctorList::removeFromName(const std::string& name)
{
    KoalaDoctorList *prev = this;
    KoalaDoctorList *tmp = m_next;

    if (m_value->getName() == name)
        return (m_next);
    while (tmp && tmp->m_value->getName() != name) {
        if (tmp == NULL)
            return (this);
        prev = tmp;
        tmp = tmp->m_next;
    }
    prev->m_next = tmp->m_next;
    return (this);
}

void KoalaDoctorList::dump()
{
    KoalaDoctorList *tmp = this;

    std::cout << "Doctors: ";
    while (tmp) {
        if (tmp->m_value)
            std::cout << tmp->m_value->getName();
        else
            std::cout << "[nullptr]";
        if (tmp->m_next)
            std::cout << ", ";
        else
            std::cout << "." << std::endl;
        tmp = tmp->m_next;
    }
}
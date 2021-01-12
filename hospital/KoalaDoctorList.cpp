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

KoalaDoctor *KoalaDoctorList::getFromName(const std::string& name)
{
    KoalaDoctorList *tmp = this;

    while (tmp != NULL) {
        if (tmp->m_value->getName() == name)
            return (tmp->m_value);
        tmp = tmp->m_next;
    }
    return (NULL);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *koala)
{
    KoalaDoctorList *prev = this;
    KoalaDoctorList *tmp = m_next;

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

KoalaDoctorList *KoalaDoctorList::removeFromName(const std::string& name)
{
    KoalaDoctorList *prev = this;
    KoalaDoctorList *tmp = m_next;

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

KoalaDoctor *KoalaDoctorList::getContent() const
{
    return (m_value);
}

KoalaDoctorList *KoalaDoctorList::getNext() const
{
    return (m_next);
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
            std::cout << ".";
        tmp = tmp->m_next;
    }
    std::cout << std::endl;
}
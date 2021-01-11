/*
** ShipWreck engine, 2020
** Hospital.cpp
*/

#include "Hospital.hpp"

Hospital::Hospital() :
m_koalaList(NULL),
m_nurseList(NULL),
m_doctorList(NULL)
{}

Hospital::~Hospital()
{}

void Hospital::addSick(SickKoalaList *koala)
{
    if (!m_koalaList)
        m_koalaList = koala;
    else
        m_koalaList->append(koala);
    std::cout
        << "[HOSPITAL] Patient "
        << koala->getContent()->getName()
        << " just arrived!"
        << std::endl;
}

void Hospital::addNurse(KoalaNurseList *nurse)
{
    if (!m_nurseList)
        m_nurseList = nurse;
    else
        m_nurseList->append(nurse);
    std::cout
        << "[HOSPITAL] Nurse "
        << nurse->getContent()->getID()
        << " just arrived!"
        << std::endl;
    nurse->getContent()->timeCheck();
}

void Hospital::addDoctor(KoalaDoctorList *doctor)
{
    if (!m_doctorList)
        m_doctorList = doctor;
    else
        m_doctorList->append(doctor);
    std::cout
        << "[HOSPITAL] Doctor "
        << doctor->getContent()->getName()
        << " just arrived!"
        << std::endl;
    doctor->getContent()->timeCheck();
}

void Hospital::run()
{
    KoalaNurseList *nurse = m_nurseList;
    KoalaDoctorList *doctor = m_doctorList;
    std::string drug;

    std::cout << "[HOSPITAL] Work starting with:" << std::endl;
    m_doctorList->dump();
    m_nurseList->dump();
    m_koalaList->dump();
    std::cout << std::endl;
    for (SickKoalaList *koala = m_koalaList; koala != NULL; koala = koala->getNext()) {
        doctor->getContent()->diagnose(koala->getContent());
        drug = nurse->getContent()->readReport(koala->getContent()->getName() + ".report");
        nurse->getContent()->giveDrug(drug, koala->getContent());
        nurse = (nurse->isEnd() ? m_nurseList : nurse->getNext());
        doctor = (doctor->isEnd() ? m_doctorList : doctor->getNext());
    }
    for (KoalaNurseList *tmp = m_nurseList; tmp != NULL; tmp = tmp->getNext())
        tmp->getContent()->timeCheck();
    for (KoalaDoctorList *tmp = m_doctorList; tmp != NULL; tmp = tmp->getNext())
        tmp->getContent()->timeCheck();
    m_koalaList->remove(m_koalaList);
    m_nurseList->remove(m_nurseList);
    m_doctorList->remove(m_doctorList);
}
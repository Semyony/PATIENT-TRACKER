/*
Final Project Milestone 5
Module: 1
Version 5.0
Author	Semen Khlavich
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/24  release 1.0
2021/07/28  release 2.0
2021/07/30  release 3.0
2021/08/01  release 4.0
2021/08/04  release 5.0
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
namespace sdds {
    bool al;
    
    PreTriage::PreTriage(const char* dataFilename)
    :m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
     m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
        m_dataFilename = new char[strLen(dataFilename) + 1];
        
        strCpy(m_dataFilename, dataFilename);
        m_averCovidWait = 15;
        m_averTriageWait = 5;
        load();
    }
    
    PreTriage::~PreTriage() {
        std::ofstream writef(m_dataFilename);
        std::cout << "Saving Average Wait Times,\n"
            "   COVID Test: " << m_averCovidWait << std::endl;
        std::cout << "   Triage: " << m_averTriageWait << std::endl;
        writef << m_averCovidWait << ',' << m_averTriageWait << '\n';
        std::cout << "Saving m_lineup..." << std::endl;
        for (int i = 0; i < m_lineupSize; i++) {
            
            std::cout << i + 1 << "- ";
            m_lineup[i]->csvWrite(writef);
            writef << '\n';
            m_lineup[i]->csvWrite(std::cout);
            std::cout << std::endl;
        }

        
        if (!al) {
            for (int i = 0; i < m_lineupSize; i++) {
                delete m_lineup[i];
                m_lineup[i] = nullptr;
            }
        }

        delete[] m_dataFilename;
        m_dataFilename = nullptr;
        std::cout << "done!\n";
    }
    void PreTriage::run(void) {
        int choice;
        while (m_appMenu >> choice) {
            switch (choice) {
            case 1:
                if (m_lineupSize < 100) {
                    reg();
                }
                else
                    std::cout << "Line up full!\n";
                break;
            case 2:
                admit();
                break;
            }
        }
    }
    void PreTriage::load() {
        std::cout << "Loading data..." << std::endl;
        std::ifstream readf(m_dataFilename);
        readf >> m_averCovidWait; 
        readf.ignore();
        readf >> m_averTriageWait;
        readf.ignore();
        al = readf.fail();
        if (al) {
            std::cout << "No data or bad data file!\n" << std::endl;
        }
        else {
            int count = 0;
            Patient* pat = nullptr;
            bool ex = false;
            for (int i = 0; ; i++) {
                char t;
                readf >> t;
                readf.ignore();
                bool ins = false;
                if (readf.fail()) {
                    break;
                }
                if (i == 100) {
                    if (!readf.fail())
                        ex = true;
                    break;
                }
                if (t == 'C') {
                    pat = new CovidPatient;
                    ins = true;
                }
                else if (t == 'T') {
                    pat = new TriagePatient;
                    ins = true;
                }
                
                if (ins) {
                    pat->fileIO(true);
                    pat->read(readf);
                    pat->fileIO(false);
                    m_lineup[i] = pat;
                    m_lineupSize++;
                    ++count;
                }
                
            
            }
            if (ex) {
                std::cout << "Warning: number of records exceeded 100" << std::endl;
            }
            std::cout << count << " Records imported...\n" << std::endl;
        }
        
    }
    void PreTriage::reg() {
        int choice;
        while (m_pMenu >> choice) {
            int l = 0;
            for (; l < m_lineupSize; l++);
            switch (choice) {
            case 1:
                m_lineup[l] = new CovidPatient;
                break;
            case 2:
                m_lineup[l] = new TriagePatient;
                break;
            default:
                std::cout << "No Option\n";
                break;
            }
            if (choice == 1 || choice == 2) {
                al = false;
                m_lineup[l]->setArrivalTime();
                std::cout << "Please enter patient information: \n";
                m_lineup[l]->read(std::cin);
                std::cout << "\n";
                if (m_lineup[l]) {
                    std::cout << "******************************************\n";
                    m_lineup[l]->write(std::cout);
                    std::cout << "Estimated Wait Time: ";
                    std::cout << getWaitTime(*m_lineup[l]) << std::endl;
                    std::cout << "******************************************\n\n";
                }
                m_lineupSize++;
                break;
            }
        }
    }
    void PreTriage::admit() {
        int choice;
        while (m_pMenu >> choice) {
            char type = '\0';
            switch (choice) {
            case 1:
                type = 'C';
                break;
            case 2:
                type = 'T';
                break;
            default:
                std::cout << "No Option\n";
                break;
            }
            
            if (choice == 1 || choice == 2 ) {
                int index = indexOfFirstInLine(type);
                if (index == -1)
                    break;

                std::cout << "\n******************************************\n";
                m_lineup[index]->fileIO(false);
                std::cout << "Calling for ";
                m_lineup[index]->write(std::cout);
                std::cout << "******************************************\n\n";
                setAverageWaitTime(*m_lineup[index]);
                removePatientFromLineup(index);
                break;
            }
        }
    }
    const Time PreTriage::getWaitTime(const Patient& p)const {
        int l = 0, z = 0;
        int wait_time = 0;
        for (int i = 0; i < m_lineupSize; i++) {
            if (m_lineup[i]->type() == 'C') {
                l++;
            }
            if (m_lineup[i]->type() == 'T') {
                z++;
            }
        }
        if (p.type() == 'C') {
            wait_time = int(m_averCovidWait) * l;
        } else
            wait_time = int(m_averTriageWait) * z;
        return  Time(wait_time);
    }
    void PreTriage::setAverageWaitTime(const Patient& p) {
        if (p.type() == 'C') {
            m_averCovidWait = ((getTime() - int(Time(p))) + (int(m_averCovidWait) * (p.number() - 1))) / p.number();
        }
        else {
            m_averTriageWait = ((getTime() - int(Time(p))) + (int(m_averTriageWait) * (p.number() - 1))) / p.number();
        }
    }
    void PreTriage::removePatientFromLineup(int index) {
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }
    int PreTriage::indexOfFirstInLine(char type) const {
        int i = 0;
        for (; ; i++) {
            if (i == m_lineupSize) {
                i = -1;
                break;
            }
            if (m_lineup[i]->type() == type)
                break;
        }
        
        return i;
    }
}
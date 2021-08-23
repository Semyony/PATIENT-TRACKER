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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include "Patient.h" 
#include "utils.h"
namespace sdds {
	Patient::Patient(int ticketNumber, bool fileIO) {
		m_ticket = ticketNumber;
		m_fileIO = fileIO;
	}
	Patient::~Patient() {
		delete[] m_name;
		m_name = nullptr;
	}

	bool Patient::fileIO() const { return m_fileIO;}

	void Patient::fileIO(bool fileIO) { m_fileIO = fileIO; }

	void Patient::setArrivalTime() { m_ticket.resetTime(); }


	bool Patient::operator == (char let)const {
		return type() == let;
	}

	bool Patient::operator == (const Patient& patient)const {
		return type() == patient.type();
	}
	Patient::operator Time() const {
		return Time(m_ticket);
	}
	int Patient::number() const {
		return m_ticket.number();
	}
	std::ostream& Patient::csvWrite(std::ostream& ostr)const {
		ostr << type() << "," << m_name << "," << m_ohip << ",";
		m_ticket.csvWrite(ostr);
		return ostr;
	}
	std::istream& Patient::csvRead(std::istream& istr) {
		if (m_name) {
			delete[] m_name;
			m_name = nullptr;
		}
		char delim = ',';
		std::string name;
		getline(istr, name, delim);
		m_name = new char[strLen(name.c_str()) + 1];
		strCpy(m_name, name.c_str());
		istr >> m_ohip >> delim;
		m_ticket.csvRead(istr);

		return istr;
	}
	std::ostream& Patient::write(std::ostream& ostr)const {
		ostr << m_ticket << "\n";
		printf("%.*s", 25, m_name);
		ostr << ", " << "OHIP: " << m_ohip;
		return ostr;
	}
	std::istream& Patient::read(std::istream& istr) {
		if (m_name) {
			delete[] m_name;
			m_name = nullptr;
		}
		std::string name;
		std::cout << "Name: ";
		getline(istr, name, '\n');
		m_name = new char[strLen(name.c_str()) + 1];
		strCpy(m_name, name.c_str());
		m_ohip = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ");

		return istr;
	}
}
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

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"
namespace sdds {
	class TriagePatient : public Patient {
		char* m_symptoms;
	public:
		TriagePatient();
		~TriagePatient();
		char type() const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
	};
}
#endif // !SDDS_TRIAGEPATIENT_H



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

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"

namespace sdds {
	class Patient : public IOAble {
		char* m_name = nullptr;
		int m_ohip = 0;
		Ticket m_ticket = 0;
		bool m_fileIO;
	public:
		Patient(int ticketNumber = 0, bool fileIO = false);
		~Patient();
		virtual char type() const = 0;
		//Patient& operator = (const Patient&) = delete;
		bool fileIO() const;
		void fileIO(bool fileIO);
		void setArrivalTime();
		bool operator == (char let)const;
		bool operator == (const Patient& patient)const;
		operator Time() const;
		int number() const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
}
#endif //!SDDS_PATIENT_H_
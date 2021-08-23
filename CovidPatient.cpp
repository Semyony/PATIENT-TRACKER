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

#include "CovidPatient.h"

namespace sdds {
   int nextCovidTicket = 1;
   CovidPatient::CovidPatient() :Patient(nextCovidTicket++) {}
   char CovidPatient::type() const { return 'C'; }
   std::istream& CovidPatient::csvRead(std::istream& istr) {
	   Patient::csvRead(istr);
	   nextCovidTicket = number() + 1;
	   return istr;
   }
   std::istream& CovidPatient::read(std::istream& istr) {
		return fileIO() ? csvRead(istr) : Patient::read(istr);
   }
   std::ostream& CovidPatient::write(std::ostream& ostr)const {
	   if (fileIO()) {
		   csvWrite(ostr);
	   }
	   else {
		   ostr << "COVID TEST\n";
		   Patient::write(ostr);
		   ostr << std::endl;
	   }
	   return ostr;
   }
}
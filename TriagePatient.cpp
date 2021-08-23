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
#include<string>
#include "utils.h"
#include "TriagePatient.h"

namespace sdds {
   int nextTriageTicket = 1;
   TriagePatient::TriagePatient() :Patient(nextTriageTicket++) {
	   m_symptoms = nullptr;
   }
   TriagePatient::~TriagePatient() {
	   delete[] m_symptoms;
	   m_symptoms = nullptr;
   }
   char TriagePatient::type() const {
	   return 'T'; 
   }
   std::istream& TriagePatient::csvRead(std::istream& istr) {
	   if (m_symptoms) {
		   delete[] m_symptoms;
		   m_symptoms = nullptr;
	   }
	   char delim = ',';
	   Patient::csvRead(istr);
	   nextTriageTicket = number() + 1;
	   istr >> delim;
	   std::string symp;
	   getline(istr, symp);
	   m_symptoms = new char[strLen(symp.c_str()) + 1];
	   strCpy(m_symptoms, symp.c_str());
	   return istr;
   }
   std::ostream& TriagePatient::csvWrite(std::ostream& ostr)const {
	   Patient::csvWrite(ostr);
	   ostr << "," << m_symptoms;
	   return ostr;
   }
   std::istream& TriagePatient::read(std::istream& istr) {
	   if (fileIO()) {
		   csvRead(istr);
	   }
	   else {
		   delete[] m_symptoms;
		   m_symptoms = nullptr;
		   Patient::read(istr);
		   char* symptoms = getcstr("Symptoms: ", istr, '\n');
		   m_symptoms = new char[strLen(symptoms) + 1];
		   strCpy(m_symptoms, symptoms);
		   delete[] symptoms;
		   symptoms = nullptr;
	   }
	   return istr;
   }
   std::ostream& TriagePatient::write(std::ostream& ostr)const {
	   if (fileIO()) {
		   csvWrite(ostr);
	   }
	   else {
		   ostr << "TRIAGE" << std::endl;
		   Patient::write(ostr);
		   ostr << std::endl;
		   ostr << "Symptoms: ";
		   ostr << m_symptoms << std::endl;
	   }
	   return ostr;
   }
}
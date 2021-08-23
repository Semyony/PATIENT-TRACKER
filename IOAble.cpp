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

#include "IOAble.h"

namespace sdds {
	IOAble::~IOAble() {}
    std::ostream& IOAble::csvWrite(std::ostream& ostr)const {
        return ostr; 
    }
    std::istream& IOAble::csvRead(std::istream& istr) {
        return istr;
    }
    std::ostream& IOAble::write(std::ostream& ostr)const {
        return ostr;
    }
    std::istream& IOAble::read(std::istream& istr) {
        return istr;
    }
    std::istream& operator>>(std::istream& istr, IOAble& I) {
        return I.read(istr);
    }
    std::ostream& operator<<(std::ostream& ostr, const IOAble& I) {
        return I.write(ostr);
    }
}
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


#ifndef _SDDS_IOABLE_H
#define _SDDS_IOABLE_H
#include <iostream>
namespace sdds {
	class IOAble {
    public:
        
        virtual std::ostream& csvWrite(std::ostream& ostr)const;
        virtual std::istream& csvRead(std::istream& istr);
        virtual std::ostream& write(std::ostream& ostr)const;
        virtual std::istream& read(std::istream& istr);
        virtual ~IOAble();
	};

    std::istream& operator>>(std::istream& istr, IOAble& I);
    std::ostream& operator<<(std::ostream& ostr, const IOAble& I);
}
#endif // !_SDDS_IOABLE_H

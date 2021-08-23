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
#include <iomanip>
#include <cmath>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time::Time(unsigned int min) {
		
		m_min = min;
	}
	std::ostream& Time::write(std::ostream& ostr) const {
		int format_h = m_min / 60;
		int format_m = m_min % 60;
		ostr << setfill('0') << setw(2) << format_h << ":" << setfill('0') << setw(2) << format_m;
		return ostr;
	}
	
	std::istream& operator>>(std::istream& istr, Time& D) {
		return D.read(istr);
	}
	std::ostream& operator<<(std::ostream& ostr, const Time& D) {
		return D.write(ostr);
	}
	Time& Time::operator-=(const Time& D) {
		double times = 0.0;
		if (m_min >= D.m_min) {
			m_min -= D.m_min;
		}
		else {
			times = double(D.m_min) / 1440.00;
			m_min = (int(ceil(times)) * 1440 + m_min) - D.m_min;
		}
		
		return *this;
	}
	Time& Time::operator+=(const Time& D) {
		m_min += D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D)const {
		int sum;
		sum = m_min + D.m_min;
		return sum;
	}

	Time& Time::operator=(unsigned int val) {
		m_min = val;
		return *this;
	}

	Time Time::operator-(const Time& D)const {
		int minus;
		double times;
		if (m_min >= D.m_min) {
			minus = m_min - D.m_min;
		}
		else {
			times = double(D.m_min) / 1440.00;
			double ceil_times = ceil(times);
			minus = (int(ceil_times) * 1440 + m_min) - D.m_min;
			
		}
		return minus;
	}
	Time& Time::operator *= (unsigned int val) {
		m_min *= val;
		return *this;
	}
	Time Time::operator *(unsigned int val)const {
		int com;
		com = m_min * val;
		return com;
	}
	
	Time& Time::operator /= (unsigned int val) {
		m_min /= val;
		return *this;
	}
	Time Time::operator /(unsigned int val)const {
		int div;
		div = m_min / val;
		return div;
	}
	
	std::istream& Time::read(std::istream& istr) {
		int hh = 0, mm = 0;
		char delim = ':';
		istr >> hh >> delim >> mm;
		if (hh < 0 || mm < 0 || delim != ':' || istr.fail()) { 
			istr.setstate(ios::failbit);
		}
		else {
			m_min = hh * 60 + mm;
		}
		return istr;
	}
	Time& Time::setToNow() {
		m_min = getTime();
		return *this;
	}
	Time::operator unsigned int()const {
		return m_min;
	}
	Time::operator int()const {
		return int(m_min);
	}
}
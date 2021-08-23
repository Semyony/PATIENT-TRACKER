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
#include <cstring>
#include "Menu.h"
#include "utils.h"
namespace sdds {
    Menu::Menu(const char* MenuContent, int NoOfSelections) {
        m_text = new char[strlen(MenuContent) + 1];
        strcpy(m_text, MenuContent);
        m_noOfSel = NoOfSelections;
    }
    Menu::~Menu() {
        delete[] m_text;
        m_text = nullptr;
    }
    int& Menu::operator>>(int& Selection) {
        display();
        int opt = getInt(0,m_noOfSel,"> ", "Invalid option ");
        Selection = opt;
        return Selection;
    }
    void Menu::display()const {
        std::cout << m_text << std::endl;
        std::cout << "0- Exit" << std::endl;
    }
}

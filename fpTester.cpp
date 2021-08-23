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
#include <fstream>
#include <cstdlib>
#include "PreTriage.h"
#include "utils.h"
using namespace std;
using namespace sdds;
void displayFile(const char* fname) {
   ifstream fin(fname);
   char ch;
   cout << endl << "******  Content of file: \"" << fname << "\":" << endl;
   while (fin.get(ch)) cout << ch;
   cout << "***************************************************" << endl << endl;
}
void copyFile(const char* des, const char* src) {
   ifstream s(src);
   ofstream d(des);
   char ch = 0;
   while (s.get(ch) && d << ch);
}

void fp2tester() {
   copyFile("smalldata.csv", "smalldata.csv.bak");
   sdds::debug = true;
   PreTriage P("smalldata.csv");
   P.run();
}
int main() {
   fp2tester();
   displayFile("smalldata.csv");
   return 0;
}



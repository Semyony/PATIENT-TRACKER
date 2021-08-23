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
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }
   int getInt(const char* prompt) {

       string Digits = "1234567890";
       string Input = "";
       int num;

       if (prompt != nullptr)
           cout << prompt;

       getline(cin, Input, '\n');

       while (1) {

           unsigned int b = 0;
           unsigned int z = 0;
           unsigned int o = 0;
           for (unsigned int i = 0; i < Input.length(); i++) 
               for (unsigned int j = 0; j < Digits.length(); j++) {
                   if (Input[i] == '-' && i == 0)
                       o++;
                   if (Input[i] == Digits[j])
                       b++;
                   if (Input[i] != Digits[j] && Input[i] != '\n')
                       z++;
                   
               }
           
           if (b == Input.length() || o)
               break;

           if (z && b && b != Input.length()) {
               cin.clear();
               cout << "Enter only an integer, try again: ";
           }
           if (!b) {
               cin.clear();
               cout << "Bad integer value, try again: ";
           }

           getline(cin, Input, '\n');
       }

       num = stoi(Input);

       return num;
   }
   int getInt(
       int min,  
       int max,  
       const char* prompt,  
       const char* errorMessage,
       bool showRangeAtError 
   ) {
       int num;

       if (prompt != nullptr)
           cout << prompt;
       while (true) {
           num = getInt();
           if (num <= max && num >= min)
               break;
           else {
               if (errorMessage != nullptr) {
                   if (showRangeAtError) {
                       cout << errorMessage << "[" << min << " <= value <= " << max << "]: ";
                   }
                   else {
                       cout << errorMessage;
                   }
               }
           }
       }
       return num;
   }
   char* getcstr(
       const char* prompt,   // User entry prompt
       std::istream& istr,  // the Stream to read from
       char delimiter   // Delimiter to mark the end of data
   ) {
       string in_str;
       if (prompt != nullptr)
           cout << prompt;
       getline(istr, in_str, delimiter);
       char* str = new char[in_str.length()+1];
       strCpy(str, in_str.c_str());

       return str;
   }

   void strCpy(char* des, const char* src) {
       while (*src) {
           *des++ = *src++;
       }
       *des = 0;
   }
   int strLen(const char* s) {
       int i = -1;
       while (s[++i]);
       return i;
   }
}
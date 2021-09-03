/* Citation and Sources...
Final Project Milestone 2
Module: utils
Filename: utils.h
Version 1.0
Author:	Rayyan Ahmed
Email: rahmed102@myseneca.ca
Student Number: 140961202
Section: NFF
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/14  Preliminary release
2021/07/14  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
    template <typename type>
    void removeDynamicElement(type* array[], int index, int& size)
    {
        delete array[index];
        for (int j = index; j < size; j++)
        {
            array[j] = array[j + 1];
        }
        size--;
    }

    extern bool debug; // making sdds::debug variable global to all the files
                      // which include: "utils.h"

   // returns the time of day in minutes
   int getTime();
   //outputs the prompt if not null and takes input from the user until a valid value is entered
   int getInt(
       const char* prompt = nullptr   // User entry prompt
   );
   //outputs the prompt if not null and takes input from the user until a valid value between the min and max range is entered
   int getInt(
       int min,   // minimum acceptable value
       int max,   // maximum acceptable value
       const char* prompt = nullptr,  // User entry prompt
       const char* errorMessage = nullptr, // Invalid value error message
       bool showRangeAtError = true    // display the range if invalud value entered 
   );
   //takes input of string and copies the string to the string pointer and returns the pointer
   char* getcstr(
       const char* prompt = nullptr,   // User entry prompt
       std::istream& istr = std::cin,  // the Stream to read from
       char delimiter = '\n'    // Delimiter to mark the end of data
   );




}
#endif // !SDDS_UTILS_H_


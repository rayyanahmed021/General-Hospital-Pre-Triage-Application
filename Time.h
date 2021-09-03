/* Citation and Sources...
Final Project Milestone 2
Module: Time
Filename: Time.h
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

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <iostream>
namespace sdds {
   class Time {
       //Time in mintues
      unsigned int m_min;
   public:
       //sets the minutes to the current time and returns the Time object
      Time& setToNow();
      //assigns the argument to the minutes if the value is greater than 0. Otherwise, it assigns zero.
      Time(unsigned int min = 0);
      //outputs to the screen the time in HH:MM format
      std::ostream& write(std::ostream& ostr) const;
      //takes input of time in HH:MM format
      std::istream& read(std::istream& istr);
      //subtracts the argument's minutes from the current object's minutes
      Time& operator-=(const Time& D);
      //subtracts the  minutes between the current object and the argument object and returns a copy
      Time operator-(const Time& D)const;
      //adds the argument's minutes to the current object's minutes
      Time& operator+=(const Time& D);
      //returns a copy of Time where the minutes are the sum of the current object's minutes and argument's minutes
      Time operator+(const Time& D)const;
      //assings the argument to the minute and returns the reference to the current object
      Time& operator=(unsigned int val);
      //multiplies the minute by the argument and returns the reference to the current object
      Time& operator *= (unsigned int val);
      //divides the minutes by the argument passed and returns the reference to the current object.
      Time& operator /= (unsigned int val);
      //returns a copy of Time where the minutes is the product of the current object's minutes and the argument passed
      Time operator *(unsigned int val)const;
      //returns a copy of Time where the minutes is assigned the value of the division of the current object's minutes and the argument passed
      Time operator /(unsigned int val)const;
      //returns minutes
      operator unsigned int()const;
      //returns minutes as an integer
      operator int()const;
   };
   //calls the write function that outputs the time in HH:MM format
   std::ostream& operator<<(std::ostream& ostr, const Time& D);
   //calls the read function that takes input of the time in HH:MM format
   std::istream& operator>>(std::istream& istr, Time& D);
}

#endif // !SDDS_TIME_H


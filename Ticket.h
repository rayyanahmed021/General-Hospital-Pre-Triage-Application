/* Citation and Sources...
Final Project Milestone 3
Module: Ticket
Filename: Ticket.h
Version 1.0
Author:	Rayyan Ahmed
Email: rahmed102@myseneca.ca
Student Number: 140961202
Section: NFF
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/15  Preliminary release
2021/07/15  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_
#include "Time.h"
#include "IOAble.h"
namespace sdds {
   class Ticket:public IOAble{
      Time m_time;
      int m_number;
   public:
       //assigns the argument to the ticket number
      Ticket(int number);
      //returns the time of the ticket
      operator Time()const;
      //returns the ticket number
      int number()const;
      //resets the time to the current time
      void resetTime();
      //displays ticket number and time with a comma
      std::ostream& csvWrite(std::ostream& ostr)const;
      //takes input of ticket number and time
      std::istream& csvRead(std::istream& istr);
      //displays ticket number and time
      std::ostream& write(std::ostream& ostr )const;
      //calls csvRead to take input of ticket number and time
      std::istream& read(std::istream& istr);
   };
}
#endif // !SDDS_TICKET_H_

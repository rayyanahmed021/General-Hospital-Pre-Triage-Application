/* Citation and Sources...
Final Project Milestone 3
Module: Ticket
Filename: Ticket.cpp
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


#include "Ticket.h"
namespace sdds {
    //assigns the argument to the ticket number
   Ticket::Ticket(int number) {
      m_number = number;
   }
   //returns the time of the ticket
   Ticket::operator Time() const {
      return m_time;
   }
   //returns the ticket number
   int Ticket::number() const {
      return m_number;
   }
   //resets the time to the current time
   void Ticket::resetTime() {
      m_time.setToNow();
   }
   //displays ticket number and time with a comma
   std::ostream& Ticket::csvWrite(std::ostream& ostr) const {
      return ostr << m_number << "," << m_time;
   }
   //takes input of ticket number and time
   std::istream& Ticket::csvRead(std::istream& istr) {
      istr >> m_number;
      istr.ignore();
      istr >> m_time;
      return istr;
   }
   //displays ticket number and time
   std::ostream& Ticket::write(std::ostream& ostr) const {
      return ostr << "Ticket No: " << m_number << ", Issued at: " << m_time ;
   }
   //calls csvRead to take input of ticket number and time
   std::istream& Ticket::read(std::istream& istr) {
      return csvRead(istr);
   }
}

/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
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

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

namespace sdds
{
	class Patient : public IOAble
	{
		char* m_patientName{ nullptr }; //dynamic
		int m_OHIP;
		Ticket ticket{0};
		bool IO_flag;
	public:
		//2-arg constructor that sets the Ticket based on the number, and assigns the flag to IO_flag
		Patient(int ticketNum = 0, bool flag = false);
		//deletes the patient's name
		~Patient();
		//safe copying logic to prevent assigning and copying
		Patient(const Patient&) = delete;
		Patient& operator = (const Patient&) = delete;
		
		//pure virtual function that returns a char
		virtual char type() const = 0;
		//returns the IO_flag
		bool fileIO()const;
		//assigns the argument to IO_flag
		void fileIO(bool file);
		//returns true if the character is the same as the type of the patient, otherwise it returns false
		bool operator == (const char character) const;
		//returns true if the type of the current patient is the same as the type of the patient in argument, otherwise it returns false
		bool operator == (const Patient&) const;
		//sets the time of ticket to current time
		void setArrivalTime();
		//returns the m_time of the time object
		operator Time() const;
		//returns ticket's number
		int number() const;
		/*int OHIP(const Patient* p) const
		{
			return p->m_OHIP;
		}*/
		//overriding virtual function
		

		//displays the type,name, OHIP and ticket info  of the patient with commas as delimeters
		std::ostream& csvWrite(std::ostream&) const;
		//reads the name, OHIP, ticket number, and ticket time and assigns the values and calls ticket.csvRead
		std::istream& csvRead(std::istream&);
		//displays the name, ticket information, and OHIP
		std::ostream& write(std::ostream&) const;
		//reads the name and OHIP from the user
		std::istream& read(std::istream&);
	};
	/*int ohip(const Patient* p)
	{
		return p->OHIP(p);
	}*/
}
#endif
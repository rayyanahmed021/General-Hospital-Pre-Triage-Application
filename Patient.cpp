/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "Patient.h"
#include "utils.h"
#include "Time.h"
using namespace std;
using namespace sdds;

namespace sdds
{
	//2-arg constructor that sets the Ticket based on the number, and assigns the flag to IO_flag
	Patient::Patient(int ticketNum, bool flag)
	{
		Ticket tick(ticketNum);
		ticket = tick;
		IO_flag = flag;
	}
	//deletes the patient's name
	Patient::~Patient()
	{
		delete[] m_patientName;
	}
	bool Patient::fileIO() const
	{
		return IO_flag;
	}
	void Patient::fileIO(bool file)
	{
		IO_flag = file;
	}
	//returns true if the character is the same as the type of the patient, otherwise it returns false
	bool Patient::operator==(const char character) const
	{
		return (character == type());
	}
	//returns true if the type of the current patient is the same as the type of the patient in argument, otherwise it returns false
	bool Patient::operator==(const Patient& patient) const
	{
		return type() == patient.type();
	}
	//sets the time of ticket to current time
	void Patient::setArrivalTime()
	{
		ticket.resetTime();
	}
	//returns the m_time of the time object
	Patient::operator Time() const
	{
		return Time(ticket);
	}
	//returns ticket's number
	int Patient::number() const
	{
		return ticket.number();
	}
	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << type() << "," << m_patientName << "," << m_OHIP << ",";
		ticket.csvWrite(ostr);
		return ostr;
	}
	//reads the name, OHIP, ticket number, and ticket time and assigns the values and calls ticket.csvRead
	std::istream& Patient::csvRead(std::istream& istr)
	{
		string str;
		delete[] m_patientName;
		getline(istr, str, ',');

		m_patientName = new char[str.length() + 1];
		strcpy(m_patientName, str.c_str());
		
		istr >> m_OHIP;
		istr.get();

		ticket.csvRead(istr);

		return istr;
	}
	//displays the name, ticket information, and OHIP
	std::ostream& Patient::write(std::ostream& ostr) const
	{
		char str[25 + 1] = "\0";
		strncpy(str, m_patientName,25);
		
		ostr << ticket << endl;
		ostr << str;
		ostr << ", OHIP: ";
		ostr << m_OHIP;

		return ostr;
	}
	//displays the name, ticket information, and OHIP
	std::istream& Patient::read(std::istream& istr)
	{
		string str;
		cout << "Name: ";
		delete[] m_patientName;

		getline(istr, str, '\n');
		m_patientName = new char[str.length() + 1];
		strcpy(m_patientName, str.c_str());

	
		m_OHIP = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ", true);
		return istr;
	}
}
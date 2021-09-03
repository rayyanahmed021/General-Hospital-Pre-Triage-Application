/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: CovidPatient.cpp
Version 1.0
Author:	Rayyan Ahmed
Email: rahmed102@myseneca.ca
Student Number: 140961202
Section: NFF
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/26  Preliminary release
2021/07/26  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include "CovidPatient.h"
using namespace std;

namespace sdds
{
	int nextCovidTicket = 1;
	//no-arg constructor that increases the nextCovidTicket by 1 and calls the 1 arg Patient constructor
	CovidPatient::CovidPatient() :Patient(nextCovidTicket)
	{
		nextCovidTicket++;
	}
	//returns 'C'
	char CovidPatient::type() const
	{
		return 'C';
	}
	//takes input using csvRead of the patient module and increases the nextCovidTicket by 1
	std::istream& CovidPatient::csvRead(std::istream& istr)
	{
		Patient::csvRead(istr);
		nextCovidTicket = number() + 1;
		istr.ignore(1000, '\n');
		return istr;
	}
	//if fileIO returns true, then calls csvWrite of Patient otherwise calls write of the patient module
	std::ostream& CovidPatient::write(std::ostream& ostr) const
	{
		if (fileIO())
		{
			Patient::csvWrite(ostr);
		}
		else
		{
			ostr << "COVID TEST" << endl;
			Patient::write(ostr);
			ostr << endl;
		}
		return ostr;
	}
	//if fileIO returns true then csvRead is called otherwise read of the patient class is called
	std::istream& CovidPatient::read(std::istream& istr)
	{
		if (fileIO())
		{
			csvRead(istr);
		}
		else
		{
			Patient::read(istr);
		}
		return istr;
	}
}
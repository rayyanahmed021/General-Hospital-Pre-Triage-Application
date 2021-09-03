/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: CovidPatient.h
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

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include "Patient.h"
namespace sdds {
	class CovidPatient : public Patient
	{
	public:
		//no-arg constructor that increases the nextCovidTicket by 1 and calls the 1 arg Patient constructor
		CovidPatient();
		//returns 'C'
		virtual char type() const;
		//takes input using csvRead of the patient module and increases the nextCovidTicket by 1
		std::istream& csvRead(std::istream&);
		//if fileIO returns true, then calls csvWrite of Patient otherwise calls write of the patient module
		std::ostream& write(std::ostream&) const;
		//if fileIO returns true then csvRead is called otherwise read of the patient class is called
		std::istream& read(std::istream&);
	};
}
#endif // !SDDS_COVIDPATIENT_H_




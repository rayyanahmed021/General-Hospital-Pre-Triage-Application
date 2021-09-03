/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: TriagePatient.h
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

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"

namespace sdds {
	class TriagePatient : public Patient
	{
		char* symptoms = nullptr;
	public:
		//no-arg constructor that assigns nullptr to symptoms and calls the 1 arg Patient constructor
		TriagePatient();
		//returns 'T'
		char type() const;
		//calls the csvWrite of the patient class and displays the symptoms
		std::ostream& csvWrite(std::ostream&) const;
		//calls csvRead of the patient class and takes input of symptoms and increases the nextTriageTicket by 1
		std::istream& csvRead(std::istream&);
		//if fileIO returns true then csvWrite is called otherwise write of the patient class is called. Also, the symptoms are displayed
		std::ostream& write(std::ostream&) const;
		//if fileOP returns true then csvRead is called otherwise read of the patient class is called. It takes input of symptoms.
		std::istream& read(std::istream&);
		//deallocates symptoms
		~TriagePatient();
	};
}
#endif // !SDDS_TRIAGEPATIENT_H



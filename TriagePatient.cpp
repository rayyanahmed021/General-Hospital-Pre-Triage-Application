/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: TriagePatient.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds
{
	int nextTriageTicket = 1;
	//no-arg constructor that assigns nullptr to symptoms and calls the 1 arg Patient constructor
	TriagePatient::TriagePatient() : Patient(nextTriageTicket)
	{
		symptoms = nullptr;
		nextTriageTicket++;
	}
	//returns 'T'
	char TriagePatient::type() const
	{
		return 'T';
	}
	//calls the csvWrite of the patient class and displays the symptoms
	std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
	{
		Patient::csvWrite(ostr);
		ostr << ",";
		ostr << symptoms;
		return ostr;
	}
	//calls csvRead of the patient class and takes input of symptoms and increases the nextTriageTicket by 1
	std::istream& TriagePatient::csvRead(std::istream& istr)
	{
		string str;
		delete[] symptoms;
		Patient::csvRead(istr);
		istr.ignore(1000, ',');
		getline(istr, str, '\n');
		symptoms = new char[str.length() + 1];
		strcpy(symptoms, str.c_str());
		nextTriageTicket = number() + 1;

		return istr;
	}
	//if fileIO returns true then csvWrite is called otherwise write of the patient class is called. Also, the symptoms are displayed
	std::ostream& TriagePatient::write(std::ostream& ostr) const
	{
		if (fileIO())
		{
			csvWrite(ostr);
		}
		else
		{
			ostr << "TRIAGE" << endl;
			Patient::write(ostr);
			ostr << endl;
			ostr << "Symptoms: " << symptoms << endl;
		}
		return ostr;
	}
	//if fileIO returns true then csvRead is called otherwise read of the patient class is called. It takes input of symptoms.
	std::istream& TriagePatient::read(std::istream& istr)
	{
		if (fileIO())
		{
			csvRead(istr);
		}
		else
		{
			string str;
			delete[] symptoms;
			Patient::read(istr);
			cout << "Symptoms: ";
			getline(istr, str, '\n');
			symptoms = new char[str.length() + 1];
			strcpy(symptoms, str.c_str());
		}
		return istr;
	}
	//deallocates symptoms
	TriagePatient::~TriagePatient()
	{
		delete[] symptoms;
	}
}
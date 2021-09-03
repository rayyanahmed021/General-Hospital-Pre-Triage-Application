/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: PreTriage.cpp
Version 1.0
Author:	Rayyan Ahmed
Email: rahmed102@myseneca.ca
Student Number: 140961202
Section: NFF
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/28  Preliminary release
2021/07/28  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"	
#include "TriagePatient.h"
#include "Patient.h"
using namespace std;


namespace sdds
{
	//assigns the argument to the filename. Calls the constructors of Menu for appMenu and pMenu. Sets the average wait time.
	PreTriage::PreTriage(const char* dataFilename) :m_averCovidWait(15),
		m_averTriageWait(5),
		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
	}
	//writes the average wait times to the file and screen and writes patient information to the file and screen. Also, it deletes the lineup and filename
	PreTriage::~PreTriage()
	{
		ofstream fout(m_dataFilename);
		fout << m_averCovidWait << "," << m_averTriageWait << endl;
		cout << "Saving Average Wait Times," << endl
			<< "   COVID Test: " << m_averCovidWait << endl
			<< "   Triage: " << m_averTriageWait << endl
			<< "Saving m_lineup..." << endl;

		for (int count = 0; count < m_lineupSize; count++)
		{
			cout << count + 1 << "- ";
			m_lineup[count]->csvWrite(cout);
			cout << endl;
			m_lineup[count]->csvWrite(fout);
			fout << endl;
		}
		delete[] m_dataFilename;
		for (int i = 0; i < m_lineupSize; i++)
		{
			delete m_lineup[i];
		}

		cout << "done!" << endl;
	}
	//displays the pMenu if space is available and takes input of patient information. Also, displays the patient information with estimated wait time.
	void PreTriage::reg()
	{
		int selection = 0;
		if (m_lineupSize >= maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
		}
		else
		{
			m_pMenu >> selection;
			if (selection == 1)
			{
				m_lineup[m_lineupSize] = new CovidPatient();
				m_lineup[m_lineupSize++]->setArrivalTime();
			}
			else if (selection == 2)
			{
				m_lineup[m_lineupSize] = new TriagePatient();
				m_lineup[m_lineupSize++]->setArrivalTime();
			}
			cout << "Please enter patient information: " << endl;
			m_lineup[m_lineupSize - 1]->fileIO(false);
			m_lineup[m_lineupSize - 1]->read(cin);
			cout << endl;

			cout << "******************************************" << endl;
			m_lineup[m_lineupSize - 1]->write(cout);
			cout << "Estimated Wait Time: ";
			cout << getWaitTime(*m_lineup[m_lineupSize - 1]) << endl;
			cout << "******************************************" << endl << endl;
		}
	}
	//displays the pMenu and finds the index of the first patient in line based on selection type. it sets the averagewaittime and remove the element.
	void PreTriage::admit()
	{
		int selection = 1, index = 0;
		m_pMenu >> selection;
		if (selection == 1)
		{
			index = indexOfFirstInLine('C');
		}
		else if (selection == 2)
		{
			index = indexOfFirstInLine('T');
		}
		if (selection && index > -1)
		{
			cout << endl << "******************************************" << endl;
			m_lineup[index]->fileIO(false);
			cout << "Calling for ";
			m_lineup[index]->write(cout);
			cout << "******************************************" << endl << endl;
			setAverageWaitTime(*m_lineup[index]);
			removePatientFromLineup(index);
		}
	}
	//displays appMenu. Based on the user input, reg or admit is called. The user exits upon entering zero
	void PreTriage::run()
	{
		int selection;
		do
		{
			m_appMenu >> selection;
			if (selection == 1)
			{
				reg();
			}
			else if (selection == 2)
			{
				admit();
			}
		} while (selection);
	}
	//counts the number of patients with the same type as the argument. Returns the product of the count by the average wait times.
	const Time PreTriage::getWaitTime(const Patient& p)const
	{
		int count = 0;
		Time temp;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == p.type() && m_lineup[i]->number() != p.number())
			{
				count++;
			}
		}
		return p.type() == 'C' ? temp = count * int(m_averCovidWait) :
			temp = count * int(m_averTriageWait);
	}
	//sets the average wait time based on the current time, patient's ticket time and the average wait time. It changes the value of the average wait times
	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		Time CT;
		CT.setToNow();
		Time PTT = (Time)(p);
		Time AWT = p.type() == 'C' ? (unsigned int)(m_averCovidWait) : (unsigned int)(m_averTriageWait);

		unsigned int PTN = p.number();
		AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
		p.type() == 'C' ? m_averCovidWait = AWT : m_averTriageWait = AWT;
	}
	//removes the patient by calling the removeDynamic element template
	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}
	//returns the index of the first patient of the same type as the argument, otherwise returns -1
	int PreTriage::indexOfFirstInLine(char type) const
	{
		int i;
		for (i = 0; i < m_lineupSize && m_lineup[i]->type() != type; i++);

		return i == m_lineupSize ? -1 : i;
	}
	//Loads data by reading average wait times from the file as well as by reading patient information from the file
	void PreTriage::load()
	{
		char type = 'x';
		Patient* p = nullptr;
		ifstream fin(m_dataFilename);
		cout << "Loading data..." << endl;

		if (fin)
		{
			fin >> m_averCovidWait;
			fin.ignore(1000, ',');
			fin >> m_averTriageWait;
			fin.ignore(1000, '\n');

			while (fin && m_lineupSize < maxNoOfPatients)
			{
				type = '\0';
				fin >> type;
				fin.ignore(1000, ',');
				if (type != '\0')
				{
					if (type == 'C')
					{
						p = new CovidPatient();
					}
					else if (type == 'T')
					{
						p = new TriagePatient();
					}
					if (p)
					{
						p->fileIO(true);
						p->csvRead(fin);
						p->fileIO(false);
						m_lineup[m_lineupSize++] = p;
					}
				}
			}
		}
		if (fin)
		{
			cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
		}
		if (!m_lineupSize)
		{
			cout << "No data or bad data file!" << endl;
		}
		else
		{
			cout << m_lineupSize << " Records imported..." << endl;
		}
		cout << endl;
	}
}
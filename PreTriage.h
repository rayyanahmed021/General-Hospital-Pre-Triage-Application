/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: PreTriage.h
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

#ifndef SDDS_PRETRIAGE_H
#define SDDS_PRETRIAGE_H

#include "Time.h"
#include "Patient.h"
#include "Menu.h"

namespace sdds
{
    const int maxNoOfPatients = 100;
    class PreTriage
    {
        //data members
        Time
            m_averCovidWait,
            m_averTriageWait;
        Patient* m_lineup[maxNoOfPatients]{};
        char* m_dataFilename = nullptr;
        int m_lineupSize = 0;
        Menu
            m_appMenu,
            m_pMenu;
        //functions

        //displays the pMenu if space is available and takes input of patient information. Also, displays the patient information with estimated wait time.
        void reg();
        //displays the pMenu and finds the index of the first patient in line based on selection type. it sets the averagewaittime and remove the element.
        void admit();
        //counts the number of patients with the same type as the argument. Returns the product of the count by the average wait times.
        const Time getWaitTime(const Patient& p)const;
        //sets the average wait time based on the current time, patient's ticket time and the average wait time. It changes the value of the average wait times
        void setAverageWaitTime(const Patient& p);
        //removes the patient by calling the removeDynamic element template
        void removePatientFromLineup(int index);
        //returns the index of the first patient of the same type as the argument, otherwise returns -1
        int indexOfFirstInLine(char type) const;
        //Loads data by reading average wait times from the file as well as by reading patient information from the file
        void load();
    public:
        //assigns the argument to the filename. Calls the constructors of Menu for appMenu and pMenu. Sets the average wait time.
        PreTriage(const char* dataFilename);
        //writes the average wait times to the file and screen and writes patient information to the file and screen. Also, it deletes the lineup and filename
        ~PreTriage();
        //displays appMenu. Based on the user input, reg or admit is called. The user exits upon entering zero
        void run();
    };

}
#endif // !SDDS_PRETRIAGE_H


/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Version 1.0
Author:	Rayyan Ahmed
Email: rahmed102@myseneca.ca
Student Number: 140961202
Section: NFF
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/14  Preliminary release
2021/07/14  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
    class Menu
    {
        char* m_text; // holds the menu content dynamically
        int m_noOfSel;  // holds the number of options displayed in menu content
        //displays the text of the menu
        void display()const;
    public:
        //2-arg Menu constructor that sets the arguments to the corresponding data members
        Menu(const char* MenuContent, int NoOfSelections);
        //deallocates the memory for text
        virtual ~Menu();
        //displays the menu text and take input of menu option through getInt
        int& operator>>(int& Selection);
        // add safe copying logic
        Menu& operator = (const Menu&) = delete;
        //copy constructor that copies the argument object into the current object after validating, otherwise, text is null
        Menu(const Menu& menu);
    };

}
#endif // !SDDS_MENU_H
/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Menu.h"
#include "utils.h"
using namespace std;
using namespace sdds;
namespace sdds
{
	//displays the text of the menu
	void Menu::display() const
	{
		cout << m_text << endl;
	}
	//2-arg Menu constructor that sets the arguments to the corresponding data members
	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
		m_noOfSel = NoOfSelections;
	}
	//deallocates the memory for text
	Menu::~Menu()
	{
		delete[] m_text;
	}
	//displays the menu text and take input of menu option through getInt
	int& Menu::operator>>(int& Selection)
	{
		display();
		cout << "0- " << "Exit" << endl;
		Selection = getInt(0, m_noOfSel, "> ","Invalid option ", true);
		return Selection;
	}
	//copy constructor that copies the argument object into the current object after validating, otherwise, text is null
	Menu::Menu(const Menu& menu)
	{
		m_noOfSel = menu.m_noOfSel;
		if (menu.m_text)
		{
			m_text = new char[strlen(menu.m_text) + 1];
			strcpy(m_text, menu.m_text);
		}
		else
		{
			m_text = nullptr;
		}
	}
}
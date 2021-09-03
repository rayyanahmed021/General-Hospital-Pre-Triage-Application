/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
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

#include "IOAble.h"
using namespace sdds;
using namespace std;
namespace sdds
{
	//calls the write function that outputs displays text
	ostream& operator<<(ostream& ostr, const IOAble& ioable)
	{	
		return ioable.write(ostr);
	}
	//calls the read function that takes input
	istream& operator>>(istream& istr, IOAble& ioable)
	{
		return ioable.read(istr);
	}
};
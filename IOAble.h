/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
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

#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>

namespace sdds
{
	class IOAble
	{
	public:
		//pure virtual function for writing to a file
		virtual std::ostream& csvWrite(std::ostream&) const = 0;
		//pure virtual function for reading from a file
		virtual std::istream& csvRead(std::istream&) = 0;
		//pure virtual function for displaying text
		virtual std::ostream& write(std::ostream&) const = 0;
		//pure virtual function for taking input from a user
		virtual std::istream& read(std::istream&) = 0;
		//virtual destructor
		virtual ~IOAble()
		{
		}
	};
	//calls the write function that outputs displays text
	std::ostream& operator << (std::ostream&, const IOAble&);
	//calls the read function that takes input
	std::istream& operator >> (std::istream&, IOAble&);
}
#endif // !SDDS_IOABLE_H
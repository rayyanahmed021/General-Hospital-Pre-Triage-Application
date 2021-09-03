/* Citation and Sources...
Final Project Milestone 2
Module: Time
Filename: Time.cpp
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

#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds
{
	//sets the minutes to the current time and returns the Time object
	Time& Time::setToNow()
	{
		m_min = getTime();
		return *this;
	}
	//assigns the argument to the minutes if the value is greater than 0. Otherwise, it assigns zero.
	Time::Time(unsigned int min)
	{
		min > 0 ? m_min = min : m_min = 0;
	}
	//outputs to the screen the time in HH:MM format
	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hrs = m_min / 60;
		int mins = m_min % 60;
		ostr.width(2);
		ostr.fill('0');
		ostr << hrs << ":";
		ostr.width(2);
		ostr << mins;
		return ostr;
	}
	//takes input of time in HH:MM format
	std::istream& Time::read(std::istream& istr)
	{
		int hrs = 0, mins = 0;
		char colon = '\0';
		istr >> hrs >> colon >> mins;

		if (mins < 0 || hrs < 0 || colon != ':')
		{
			istr.setstate(ios::failbit);
		}
		else
		{
			m_min = (hrs * 60) + mins;
		}
		return istr;
	}
	//subtracts the argument's minutes from the current object's minutes
	Time& Time::operator-=(const Time& D)
	{
		double hrs = 0.0;

		if (m_min < D.m_min)
		{
			hrs = (D.m_min / 60.0) / 24.0;
			if (hrs != (int)hrs)
			{
				hrs = (int)(hrs + 1);
			}
			m_min += (hrs * 24 * 60);
		}
		m_min -= D.m_min;

		return *this;
	}
	//subtracts the  minutes between the current object and the argument object and returns a copy
	Time Time::operator-(const Time& D) const
	{
		Time cpy = *this;
		double hrs;

		if (m_min < D.m_min)
		{
			hrs = (D.m_min / 60.0) / 24.0;
			if (hrs != (int)hrs)
			{
				hrs = (int)(hrs + 1);
			}
			cpy.m_min = m_min + (hrs * 24 * 60);
		}
		cpy.m_min -= D.m_min;

		return cpy;
	}
	//adds the argument's minutes to the current object's minutes
	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;
		return *this;
	}
	//returns a copy of Time where the minutes are the sum of the current object's minutes and argument's minutes
	Time Time::operator+(const Time& D) const
	{
		Time cpy;
		cpy.m_min = m_min + D.m_min;
		return cpy;
	}
	//assings the argument to the minute and returns the reference to the current object
	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}
	//multiplies the minute by the argument and returns the reference to the current object
	Time& Time::operator*=(unsigned int val)
	{
		m_min *= val;
		return *this;
	}
	//divides the minutes by the argument passed and returns the reference to the current object.
	Time& Time::operator/=(unsigned int val)
	{
		m_min /= val;
		return *this;
	}
	//returns a copy of Time where the minutes is the product of the current object's minutes and the argument passed
	Time Time::operator*(unsigned int val) const
	{
		Time cpy;
		cpy.m_min = m_min * val;
		return cpy;
	}
	//returns a copy of Time where the minutes is assigned the value of the division of the current object's minutes and the argument passed
	Time Time::operator/(unsigned int val) const
	{
		Time temp;
		temp.m_min = m_min / val;
		return temp;
	}
	//returns minutes
	Time::operator unsigned int() const
	{
		return m_min;
	}
	//returns minutes as an integer
	Time::operator int() const
	{
		return int(m_min);
	}
	//calls the write function that outputs the time in HH:MM format
	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		D.write(ostr);
		return ostr;
	}
	//calls the read function that takes input of the time in HH:MM format
	std::istream& operator>>(std::istream& istr, Time& D)
	{
		D.read(istr);
		return istr;
	}

}
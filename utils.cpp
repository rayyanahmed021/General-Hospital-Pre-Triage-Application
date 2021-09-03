/* Citation and Sources...
Final Project Milestone 2
Module: utils
Filename: utils.cpp
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
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds
{
	bool debug = false;  // made global in utils.h
	int getTime() {  
	   int mins = -1;
	   if (debug) {
	      Time t(0);
	      cout << "Enter current time: ";
	      do {
	         cin.clear();
	         cin >> t;   // needs extraction operator overloaded for Time
	         if (!cin) {
	            cout << "Invlid time, try agian (HH:MM): ";
	            cin.clear();
	         }
	         else {
	            mins = int(t);
	         }
	         cin.ignore(1000, '\n');
	      } while (mins < 0);
	   }
	   else {
	      time_t t = time(NULL);
	      tm lt = *localtime(&t);
	      mins = lt.tm_hour * 60 + lt.tm_min;
	   }
	   return mins;
	}
	//outputs the prompt if not null and takes input from the user until a valid value is entered
	int getInt(const char* prompt)
	{
		int flag, inputPrompt;

		if (prompt)
		{
			cout << prompt;
		}
		do
		{
			flag = 1;
			cin >> inputPrompt;

			if (cin.fail())
			{
				cerr << "Bad integer value, try again: ";
				flag = 0;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else if (cin.get() != '\n')
			{
				cerr << "Enter only an integer, try again: ";
				flag = 0;
				cin.clear();
				cin.ignore(1000, '\n');
			}
		} while (!flag);

		return inputPrompt;
	}
	//outputs the prompt if not null and takes input from the user until a valid value between the min and max range is entered
	int getInt(int min, int max, const char* prompt,
		const char* errorMessage, bool showRangeAtError)
	{
		int flag, inputPrompt;

		if (prompt)
		{
			cout << prompt;
		}
		do
		{
			flag = 1;
			cin >> inputPrompt;

			if (cin.fail())
			{
				cerr << "Bad integer value, try again: ";
				flag = 0;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else if (cin.get() != '\n')
			{
				cerr << "Enter only an integer, try again: ";
				flag = 0;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else if (inputPrompt < min || inputPrompt > max)
			{
				flag = 0;
				if (errorMessage)
				{
					cerr << errorMessage;
				}
				if (showRangeAtError)
				{
					cerr << "[" << min << " <= value <= " << max << "]: ";
				}
			}
		} while (!flag);

		return inputPrompt;
	}
	//takes input of string and copies the string to the string pointer and returns the pointer
	char* getcstr(const char* prompt, std::istream& istr, char delimiter)
	{
		string str;
		char* ptr = nullptr;
		if (prompt)
		{
			cout << prompt;
			getline(istr,str);
		}
		ptr = new char[str.length() + 1];
		strcpy(ptr, str.c_str());
		
		return ptr;
	}
}